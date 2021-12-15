#ifndef Disk_Manager_h_
#define Disk_Manager_h_

#include <vector>
#include <string>
using std::vector;
using std::string;

struct HardDrive
{
	string productId, serialNumber;
	unsigned long bytesPerSector, sectorsPerTrack, tracksPerCylinder;
	long long diskSize, cylinders;
	string driveType;
};

struct LogicalDrive
{
	string pathName, volumeName, fileSystemName;
	unsigned long bytesPerSector, sectorsPerCluster, freeClusters, allClusters;
	//unsigned long serialNumber;
	long long size, sizeFree, sizeUsed;
	string type;
};

typedef vector<HardDrive*> ListHardDrive;
typedef vector<LogicalDrive*> ListLogicalDrive;
class HardDriveInfo
{
private:
	ListHardDrive listHardDrive;
	char* getString(const char* str, int pos, char* buf);
	void destroyListHardDrives();
public:
	int readHardDrives();
	ListHardDrive getHardDrives();
	HardDriveInfo();
	virtual ~HardDriveInfo();
};
class LogicalDriveInfo 
{
private:
	ListLogicalDrive listLogicalDrive;
	void destroyListLogicalDrives();
public:
	int readLogicalDrives();
	ListLogicalDrive getLogicalDrives();
	LogicalDriveInfo();
	virtual ~LogicalDriveInfo();
};

#endif
