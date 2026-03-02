#include "../../include/scheduler/SJF.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

SJF::SJF(std::vector<Process> procs) : processes(procs) {
    std::sort(processes.begin(), processes.end(), 
        [](const Process& a, const Process& b) {
            return a.getArrivalTime() < b.getArrivalTime();
        });
}

void SJF::execute() {
    int currentTime = 0;
    std::vector<Process> completed;
    std::vector<bool> isCompleted(processes.size(), false);
    
    std::cout << "\n=== SJF Execution ===" << std::endl;
    
    while (completed.size() < processes.size()) {
        int shortestIdx = -1;
        int shortestBurst = 999999;
        
        for (int i = 0; i < processes.size(); i++) {
            if (!isCompleted[i] && 
                processes[i].getArrivalTime() <= currentTime &&
                processes[i].getBurstTime() < shortestBurst) {
                shortestBurst = processes[i].getBurstTime();
                shortestIdx = i;
            }
        }
        
        if (shortestIdx == -1) {
            for (int i = 0; i < processes.size(); i++) {
                if (!isCompleted[i]) {
                    currentTime = processes[i].getArrivalTime();
                    break;
                }
            }
            continue;
        }
        
        Process& p = processes[shortestIdx];
        
        int waitTime = currentTime - p.getArrivalTime();
        p.setWaitingTime(waitTime);
        
        std::cout << "Time " << currentTime << ": P" << p.getPid() 
                  << " starts executing" << std::endl;
        
        int startTime = currentTime;
        currentTime += p.getBurstTime();
        
        gantt.addEntry(p.getPid(), startTime, currentTime);
        
        p.setCompletionTime(currentTime);
        int turnaroundTime = currentTime - p.getArrivalTime();
        p.setTurnaroundTime(turnaroundTime);
        
        std::cout << "Time " << currentTime << ": P" << p.getPid() 
                  << " completes" << std::endl;
        
        isCompleted[shortestIdx] = true;
        completed.push_back(p);
    }
}

void SJF::displayResults() {
    gantt.display();
    
    std::cout << "\n=== Results ===" << std::endl;
    std::cout << "PID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround" << std::endl;
    
    int totalWaiting = 0;
    int totalTurnaround = 0;
    
    for (const auto& p : processes) {
        std::cout << "P" << p.getPid() << "\t"
                  << p.getArrivalTime() << "\t"
                  << p.getBurstTime() << "\t"
                  << p.getCompletionTime() << "\t\t"
                  << p.getWaitingTime() << "\t"
                  << p.getTurnaroundTime() << std::endl;
        
        totalWaiting += p.getWaitingTime();
        totalTurnaround += p.getTurnaroundTime();
    }
    
    std::cout << "\nAverage Waiting Time: " 
              << (float)totalWaiting / processes.size() << std::endl;
    std::cout << "Average Turnaround Time: " 
              << (float)totalTurnaround / processes.size() << std::endl;
}
