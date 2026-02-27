#include <iostream>
#include <vector>
#include "../include/core/Process.hpp"
#include "../include/scheduler/FCFS.hpp"

int main() {
    std::cout << "=== CPU Scheduler ===" << std::endl;
    std::cout << std::endl;
    
    std::vector<Process> processes;
    processes.push_back(Process(1, 0, 5));
    processes.push_back(Process(2, 1, 3));
    processes.push_back(Process(3, 2, 8));
    processes.push_back(Process(4, 3, 6));
    
    FCFS scheduler(processes);
    scheduler.execute();
    scheduler.displayResults();
        
    return 0;
}
