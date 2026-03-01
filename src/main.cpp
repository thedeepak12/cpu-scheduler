#include <iostream>
#include <vector>
#include "../include/core/Process.hpp"
#include "../include/scheduler/FCFS.hpp"
#include "../include/utils/InputHandler.hpp"

int main() {
    std::cout << "=== CPU Scheduler ===" << std::endl;
    std::cout << std::endl;

    std::cout << "\nSelect input method:" << std::endl;
    std::cout << "1. Enter process data manually" << std::endl;
    std::cout << "2. Use default test data" << std::endl;
    std::cout << "Choice: ";

    int choice;
    std::cin >> choice;

    std::vector<Process> processes;

    if (choice == 1) {
        processes = InputHandler::readFromConsole();
    } else {
        std::cout << "\nUsing default test data..." << std::endl;
        processes = InputHandler::getDefaultData();
    }

    if (processes.empty()) {
        std::cout << "No processes to schedule!" << std::endl;
        return 1;
    }

    
    FCFS scheduler(processes);
    scheduler.execute();
    scheduler.displayResults();
        
    return 0;
}
