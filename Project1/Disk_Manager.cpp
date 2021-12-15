// Disk_Manager.cpp : Defines the entry point for the console application.
//

#include "Disk_Manager.h"
#include <Windows.h>
#include <iostream>
#include <map>
using namespace std;
#define  MAX_IDE_DRIVES  16
#define IOCTL_DISK_GET_DRIVE_GEOMETRY_EX CTL_CODE(IOCTL_DISK_BASE, 0x0028, METHOD_BUFFERED, FILE_ANY_ACCESS)
std::map<int, string> mediaType = {
	{0,"Unknown"},                // Format is unknown
	{1,"F5_1Pt2_512"},            // 5.25", 1.2MB,  512 bytes/sector
	{2,"F3_1Pt44_512"},           // 3.5",  1.44MB, 512 bytes/sector
	{3,"F3_2Pt88_512"},           // 3.5",  2.88MB, 512 bytes/sector
	{4,"F3_20Pt8_512"},           // 3.5",  20.8MB, 512 bytes/sector
	{5,"F3_720_512"},             // 3.5",  720KB,  512 bytes/sector
	{6,"F5_360_512"},             // 5.25", 360KB,  512 bytes/sector
	{7,"F5_320_512"},             // 5.25", 320KB,  512 bytes/sector
	{8,"F5_320_1024"},            // 5.25", 320KB,  1024 bytes/sector
	{9,"F5_180_512"},             // 5.25", 180KB,  512 bytes/sector
	{10,"F5_160_512"},             // 5.25", 160KB,  512 bytes/sector
	{11,"Removable Media"},         // Removable media other than floppy
	{12,"Fixed Media"},             // Fixed hard disk media
	{13,"F3_120M_512"},            // 3.5", 120M Floppy
	{14,"F3_640_512"},             // 3.5" ,  640KB,  512 bytes/sector
	{15,"F5_640_512"},             // 5.25",  640KB,  512 bytes/sector
	{16,"F5_720_512"},             // 5.25",  720KB,  512 bytes/sector
	{17,"F3_1Pt2_512"},            // 3.5" ,  1.2Mb,  512 bytes/sector
	{18,"F3_1Pt23_1024"},          // 3.5" ,  1.23Mb, 1024 bytes/sector
	{19,"F5_1Pt23_1024"},          // 5.25",  1.23MB, 1024 bytes/sector
	{20,"F3_128Mb_512"},           // 3.5" MO 128Mb   512 bytes/sector
	{21,"F3_230Mb_512"},           // 3.5" MO 230Mb   512 bytes/sector
	{22,"F8_256_128"},             // 8",     256KB,  128 bytes/sector
	{23,"F3_200Mb_512"},           // 3.5",   200M Floppy (HiFD)
	{24,"F3_240M_512"},            // 3.5",   240Mb Floppy (HiFD)
	{25,"F3_32M_512"}              // 3.5",   32Mb Floppy
};
std::map<int, string> description = {
	{ 0, "Unknown" },
	{ 1, "No Root Directory" },
	{ 2, "Removable Disk" },
	{3,"Local Disk"},
	{4,"Network Drive"},
	{5,"Compact Disc"},
	{6,"RAM Disk"}
};


HardDriveInfo::HardDriveInfo(void)
{
	this->readHardDrives();
}
LogicalDriveInfo::LogicalDriveInfo(void)
{
	this->readLogicalDrives();
}

int HardDriveInfo::readHardDrives()
{
	this->destroyListHardDrives();
	int drive = 0;
	HardDrive* hardDrive;
	for (drive = 0; drive < MAX_IDE_DRIVES; drive++)
	{
		HANDLE hPhysicalDrive = 0;
		char driveName[256];
		sprintf_s(driveName, "\\\\.\\PhysicalDrive%d", drive);

		WCHAR name[256];
		MultiByteToWideChar(0, 0, driveName, 255, name, 256);

		hPhysicalDrive = CreateFile((LPCWSTR)name, 0,
			FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
			OPEN_EXISTING, 0, NULL);

		if (hPhysicalDrive != INVALID_HANDLE_VALUE)
		{
		
			STORAGE_PROPERTY_QUERY query;
			DWORD cbBytesReturned = 0;
			char buffer[10000];	
			memset((void*)&query, 0, sizeof(query));
			query.PropertyId = StorageDeviceProperty;
			query.QueryType = PropertyStandardQuery;
			memset(buffer, 0, sizeof(buffer));
			
			if (DeviceIoControl(hPhysicalDrive, IOCTL_STORAGE_QUERY_PROPERTY,
				&query,
				sizeof(query),
				&buffer,
				sizeof(buffer),
				&cbBytesReturned, NULL))
			{
				STORAGE_DEVICE_DESCRIPTOR* descrip = (STORAGE_DEVICE_DESCRIPTOR*)&buffer;
				char serialNumber[1000];
				char modelNumber[1000];
				
				getString(buffer, descrip->ProductIdOffset, modelNumber);
				getString(buffer, descrip->SerialNumberOffset, serialNumber);
				
				hardDrive = new HardDrive;
				hardDrive->productId = string(modelNumber);
				hardDrive->serialNumber = string(serialNumber);
				hardDrive->bytesPerSector = 0;
				hardDrive->cylinders = 0;
				hardDrive->diskSize = 0;
				hardDrive->tracksPerCylinder = 0;
				hardDrive->sectorsPerTrack = 0;
				hardDrive->driveType = mediaType[0];
				listHardDrive.push_back(hardDrive);

				memset(buffer, 0, sizeof(buffer));
				if (DeviceIoControl(hPhysicalDrive,
					IOCTL_DISK_GET_DRIVE_GEOMETRY_EX,
					NULL,
					0,
					&buffer,
					sizeof(buffer),
					&cbBytesReturned,
					NULL))
				{
					DISK_GEOMETRY_EX* geom = (DISK_GEOMETRY_EX*)&buffer;
					int fixed = (geom->Geometry.MediaType == FixedMedia);
					__int64 size = geom->DiskSize.QuadPart;
					
					hardDrive->bytesPerSector = geom->Geometry.BytesPerSector;
					hardDrive->cylinders = geom->Geometry.Cylinders.QuadPart;
					hardDrive->diskSize = geom->DiskSize.QuadPart;
					hardDrive->tracksPerCylinder = geom->Geometry.TracksPerCylinder;
					hardDrive->sectorsPerTrack = geom->Geometry.SectorsPerTrack;
					hardDrive->driveType = mediaType[geom->Geometry.MediaType];
				}
			}
			CloseHandle(hPhysicalDrive);
		}
	}
	return drive;
}
int LogicalDriveInfo::readLogicalDrives()
{
	this->destroyListLogicalDrives();
	const int lenght = 255;
	char buffer[lenght + 1];
	WCHAR names[256];
	
	::GetLogicalDriveStrings(lenght, names);

	for (int i = 0; i < 256; i++) {
		buffer[i] = (char)names[i];
	}
	char* s = buffer;

	
	while (*s)	{
		LogicalDrive* volumeInfo = new LogicalDrive;
		volumeInfo->pathName = s;
		listLogicalDrive.push_back(volumeInfo);
		s += strlen(s) + 1;
	}
	WCHAR VolumeNameBuffer[256], FileSystemBuffer[256];
	for (unsigned int i = 0; i < listLogicalDrive.size(); i++)
	{
		memset(VolumeNameBuffer, 0, 256 * sizeof(WCHAR));
		memset(FileSystemBuffer, 0, 256 * sizeof(WCHAR));
		unsigned long bytesPerSector = 0;
		unsigned long sectorsPerCluster = 0;
		unsigned long freeClusters = 0;
		unsigned long allClusters = 0;
		unsigned long serialNumber = 0;
		unsigned long maximumComponentLength = 0;
		unsigned long fileSystemFlags = 0;
		int driverType;

		WCHAR rootPath[5];
		MultiByteToWideChar(0, 0, listLogicalDrive[i]->pathName.data(), 5, rootPath, 5);

		driverType = ::GetDriveType((LPCWSTR)rootPath);

		::GetDiskFreeSpace(
			(LPCWSTR)rootPath,
			&sectorsPerCluster,
			&bytesPerSector,
			&freeClusters,
			&allClusters
		);

		::GetVolumeInformation(
			(LPCWSTR)rootPath,
			(LPWSTR)VolumeNameBuffer,
			256,
			&serialNumber,
			&maximumComponentLength,
			&fileSystemFlags,
			(LPWSTR)FileSystemBuffer,
			256
		);
		//Convert WCHAR * to char *
		char volumName[256], fileSystem[256];
		for (int i = 0; i < 256; i++) {
			volumName[i] = (char)VolumeNameBuffer[i];
			fileSystem[i] = (char)FileSystemBuffer[i];
		}
		listLogicalDrive[i]->type = description[driverType];
		listLogicalDrive[i]->freeClusters = freeClusters;
		listLogicalDrive[i]->bytesPerSector = bytesPerSector;
		listLogicalDrive[i]->sectorsPerCluster = sectorsPerCluster;
		listLogicalDrive[i]->allClusters = allClusters;
		listLogicalDrive[i]->volumeName = string(volumName);
		listLogicalDrive[i]->fileSystemName = string(fileSystem);
		listLogicalDrive[i]->size = bytesPerSector * sectorsPerCluster * (long long)allClusters;
		listLogicalDrive[i]->sizeFree = bytesPerSector * sectorsPerCluster * (long long)freeClusters;
		listLogicalDrive[i]->sizeUsed = listLogicalDrive[i]->size - listLogicalDrive[i]->sizeFree;
	}
	return this->listLogicalDrive.size();
}


char* HardDriveInfo::getString(const char* str, int pos, char* buf)
{
	buf[0] = 0;
	if (pos <= 0)
		return buf;

	int i = pos;
	int j = 1;
	int k = 0;
	while (j && str[i] != 0)
	{
		char c = str[i];
		if (!isprint(c))
		{
			j = 0;
			break;
		}
		buf[k] = c;
		++k;
		++i;
	}

	if (!j)
		k = 0;

	buf[k] = 0;

	while (isspace(buf[0]) && buf[0] != 0)
	{
		i = 0;
		while (buf[i] != 0)
		{
			buf[i] = buf[i + 1];
			i++;
		}
	}
	if (strlen((buf)) > 1)
		while (isspace(buf[strlen(buf) - 1]))
		{
			buf[strlen(buf) - 1] = 0;
		}

	return buf;
}

void LogicalDriveInfo::destroyListLogicalDrives()
{
	while (!listLogicalDrive.empty())
	{
		delete listLogicalDrive.back();
		listLogicalDrive.pop_back();
	}
}

void HardDriveInfo::destroyListHardDrives()
{
	while (!listHardDrive.empty())
	{
		delete listHardDrive.back();
		listHardDrive.pop_back();
	}
}


HardDriveInfo::~HardDriveInfo()
{
	this->destroyListHardDrives();
}
LogicalDriveInfo::~LogicalDriveInfo()
{
	this->destroyListLogicalDrives();
}

ListHardDrive HardDriveInfo::getHardDrives()
{
	return this->listHardDrive;
}

ListLogicalDrive LogicalDriveInfo::getLogicalDrives()
{
	return this->listLogicalDrive;
}





