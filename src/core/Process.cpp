#include "../../include/core/Process.hpp"
#include <iostream>

Process::Process(int pid, int arrival, int burst)
    : pid(pid), arrivalTime(arrival), burstTime(burst), 
      waitingTime(0), turnaroundTime(0), completionTime(0) {}

int Process::getPid() const { return pid; }
int Process::getArrivalTime() const { return arrivalTime; }
int Process::getBurstTime() const { return burstTime; }
int Process::getWaitingTime() const { return waitingTime; }
int Process::getTurnaroundTime() const { return turnaroundTime; }
int Process::getCompletionTime() const { return completionTime; }

void Process::setWaitingTime(int time) { waitingTime = time; }
void Process::setTurnaroundTime(int time) { turnaroundTime = time; }
void Process::setCompletionTime(int time) { completionTime = time; }

void Process::display() const {
    std::cout << "P" << pid 
              << " | Arrival: " << arrivalTime 
              << " | Burst: " << burstTime << std::endl;
}
