#include "../../include/scheduler/RoundRobin.hpp"
#include <iostream>
#include <algorithm>
#include <queue>

RoundRobin::RoundRobin(std::vector<Process> procs, int quantum)
    : processes(procs), timeQuantum(quantum) {
    std::sort(processes.begin(), processes.end(), 
        [](const Process& a, const Process& b) {
            return a.getArrivalTime() < b.getArrivalTime();
        });
}

void RoundRobin::execute() {
    int currentTime = 0;
    std::queue<int> readyQueue;
    std::vector<bool> inQueue(processes.size(), false);
    int completed = 0;

    std::cout << "\n=== Round Robin Execution (Time Quantum = " << timeQuantum << ") ===" << std::endl;

    if (!processes.empty() && processes[0].getArrivalTime() == 0) {
        readyQueue.push(0);
        inQueue[0] = true;
    }

    while (completed < processes.size()) {
        for (size_t i = 0; i < processes.size(); i++) {
            if (!inQueue[i] && 
                processes[i].getArrivalTime() <= currentTime && 
                processes[i].getRemainingTime() > 0) {
                readyQueue.push(i);
                inQueue[i] = true;
            }
        }

        if (readyQueue.empty()) {
            for (size_t i = 0; i < processes.size(); i++) {
                if (processes[i].getRemainingTime() > 0) {
                    currentTime = processes[i].getArrivalTime();
                    readyQueue.push(i);
                    inQueue[i] = true;
                    break;
                }
            }
        }

        int idx = readyQueue.front();
        readyQueue.pop();
        inQueue[idx] = false;

        Process& p = processes[idx];

        int execTime = std::min(timeQuantum, p.getRemainingTime());

        std::cout << "Time " << currentTime << ": P" << p.getPid() << " executes for " << execTime << " units" << std::endl;

        int startTime = currentTime;
        currentTime += execTime;
        p.setRemainingTime(p.getRemainingTime() - execTime);

        gantt.addEntry(p.getPid(), startTime, currentTime);

        for (size_t i = 0; i < processes.size(); i++) {
            if (!inQueue[i] && 
                processes[i].getArrivalTime() <= currentTime && 
                processes[i].getRemainingTime() > 0 &&
                i != (size_t)idx) {
                readyQueue.push(i);
                inQueue[i] = true;
            }
        }

        if (p.getRemainingTime() == 0) {
            p.setCompletionTime(currentTime);
            p.setTurnaroundTime(currentTime - p.getArrivalTime());
            p.setWaitingTime(p.getTurnaroundTime() - p.getBurstTime());

            completed++;
            std::cout << "Time " << currentTime << ": P" << p.getPid() << " completes" << std::endl;
        } else {
            readyQueue.push(idx);
            inQueue[idx] = true;
        }
    }
}

void RoundRobin::displayResults() {
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
