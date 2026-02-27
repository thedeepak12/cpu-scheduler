#include <iostream>
#include <vector>
#include "../include/core/Process.hpp"

int main() {
    std::cout << "=== CPU Scheduler ===" << std::endl;
    std::cout << std::endl;
    
    std::vector<Process> processes;
    processes.push_back(Process(1, 0, 5));
    processes.push_back(Process(2, 1, 3));
    processes.push_back(Process(3, 2, 8));
    processes.push_back(Process(4, 3, 6));
    
    std::cout << "Created Processes:" << std::endl;
    for (const auto& p : processes) {
        p.display();
    }
        
    return 0;
}
