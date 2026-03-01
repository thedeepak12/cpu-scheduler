#include "../../include/utils/InputHandler.hpp"
#include <iostream>

std::vector<Process> InputHandler::readFromConsole() {
    std::vector<Process> processes;
    int numProcesses;

    std::cout << "\nEnter number of processes: ";
    std::cin >> numProcesses;

    std::cout << "\nEnter process details (Arrival Time, Burst Time): " << std::endl;

    for (int i = 0; i < numProcesses; i++) {
        int arrival, burst;
        std::cout << "Process " << (i + 1) << ": ";
        std::cin >> arrival >> burst;
        processes.push_back(Process(i + 1, arrival, burst));
    }

    return processes;
}

std::vector<Process> InputHandler::getDefaultData() {
    std::vector<Process> processes;
    processes.push_back(Process(1, 0, 24));
    processes.push_back(Process(2, 0, 3));
    processes.push_back(Process(3, 0, 3));
    return processes;
}
