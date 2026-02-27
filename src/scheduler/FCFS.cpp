#include "../../include/scheduler/FCFS.hpp"
#include <iostream>
#include <algorithm>

FCFS::FCFS(std::vector<Process> procs) : processes(procs) {
    std::sort(processes.begin(), processes.end(),
        [](const Process& a, const Process& b) {
            return a.getArrivalTime() < b.getArrivalTime();
        });
}

void FCFS::execute() {
    int currentTime = 0;

    std::cout << "\n=== FCFS Execution ===" << std::endl;

    for (auto& process : processes) {
        if (currentTime < process.getArrivalTime()) {
            currentTime = process.getArrivalTime();
        }

        int waitTime = currentTime - process.getArrivalTime();
        process.setWaitingTime(waitTime);

        std::cout << "Time " << currentTime << ": P" << process.getPid() 
                  << " starts executing" << std::endl;

        currentTime += process.getBurstTime();

        process.setCompletionTime(currentTime);
        int turnaroundTime = currentTime - process.getArrivalTime();
        process.setTurnaroundTime(turnaroundTime);

        std::cout << "Time " << currentTime << ": P" << process.getPid() 
                  << " completes" << std::endl;
    }
}

void FCFS::displayResults() {
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
