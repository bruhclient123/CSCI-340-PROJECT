/*
C++ LIBRARY PROJECT
ELHADJI KEITA
ID: 24477961
CSCI-340
SIMOS.H FILE
*/

#include <iostream>
#include <vector>
#include <queue>
struct FileReadRequest

{

    int  PID{0};

    std::string fileName{""};

};

 

struct MemoryItem
{
    unsigned long long pageNumber;
    unsigned long long frameNumber;
    int PID; // PID of the process using this frame of memory
};

 

using MemoryUsage = std::vector<MemoryItem>;

 

constexpr int NO_PROCESS{ 0 };

class SimOS
{
private:
    /* data */
public:
    SimOS( int numberOfDisks, unsigned long long amountOfRAM, unsigned int pageSize);

    void NewProcess();

    void SimFork();

    void SimExit();

    void SimWait();

    void TimerInterrupt();

    void DiskReadRequest( int diskNumber, std::string fileName);

    void DiskJobCompleted( int diskNumber);

    void AccessMemoryAddress(unsigned long long address);

    int GetCPU();

    std::deque<int> GetReadyQueue( );

    MemoryUsage GetMemory();

    FileReadRequest GetDisk( int diskNumber);

    std::deque<FileReadRequest> GetDiskQueue( int diskNumber );
};

