#include "../../include/scheduler/SRTF.hpp"
#include <iostream>
#include <algorithm>
#include <climits>

SRTF::SRTF(std::vector<Process> procs) : processes(procs) {
    std::sort(processes.begin(), processes.end(), 
        [](const Process& a, const Process& b) {
            return a.getArrivalTime() < b.getArrivalTime();
        });
}

void SRTF::execute() {
    int currentTime = 0;
    int completed = 0;
    int lastProcess = -1;
    int lastStartTime = 0;

    std::cout << "\n=== SRTF Execution ===" << std::endl;

    int maxTime = 0;
    for (const auto& p : processes) {
        maxTime += processes.back().getArrivalTime();
    }

    while (completed < processes.size()) {
        int shortestIdx = -1;
        int shortestRemaining = INT_MAX;

        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].getArrivalTime() <= currentTime && processes[i].getRemainingTime() > 0 && processes[i].getRemainingTime() < shortestRemaining) {
                shortestRemaining = processes[i].getRemainingTime();
                shortestIdx = i;
            }
        }

        if (shortestIdx == -1) {
            currentTime++;
            continue;
        }

        if (lastProcess != -1 && lastProcess != shortestIdx) {
            gantt.addEntry(processes[lastProcess].getPid(), lastStartTime, currentTime);
            lastStartTime = currentTime;
        } else if (lastProcess == -1) {
            lastStartTime = currentTime;
        }

        Process& p = processes[shortestIdx];
        p.setRemainingTime(p.getRemainingTime() - 1);
        currentTime++;
        lastProcess = shortestIdx;

        if (p.getRemainingTime() == 0) {
            gantt.addEntry(p.getPid(), lastStartTime, currentTime);

            p.setCompletionTime(currentTime);
            p.setTurnaroundTime(currentTime - p.getArrivalTime());
            p.setWaitingTime(p.getTurnaroundTime() - p.getBurstTime());

            std::cout << "Time " << currentTime << ": P" << p.getPid() << " completes" << std::endl;
            
            completed++;
            lastProcess = -1;
        }
    }
}

void SRTF::displayResults() {
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
    
    std::cout << "\nAverage Waiting Time: " << (float)totalWaiting / processes.size() << std::endl;
    std::cout << "Average Turnaround Time: " << (float)totalTurnaround / processes.size() << std::endl;
}
