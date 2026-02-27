#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <string>

class Process {
private:
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;

public:
    Process(int pid, int arrival, int burst);
    
    int getPid() const;
    int getArrivalTime() const;
    int getBurstTime() const;
    int getWaitingTime() const;
    int getTurnaroundTime() const;
    int getCompletionTime() const;
    
    void setWaitingTime(int time);
    void setTurnaroundTime(int time);
    void setCompletionTime(int time);
    
    void display() const;
};

#endif
