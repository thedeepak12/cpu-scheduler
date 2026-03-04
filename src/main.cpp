#include <iostream>
#include <vector>
#include "../include/core/Process.hpp"
#include "../include/scheduler/FCFS.hpp"
#include "../include/scheduler/SJF.hpp"
#include "../include/scheduler/RoundRobin.hpp"
#include "../include/scheduler/Priority.hpp"
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

    std::cout << "\nSelect scheduling algorithm:" << std::endl;
    std::cout << "1. FCFS (First Come First Serve)" << std::endl;
    std::cout << "2. SJF (Shortest Job First)" << std::endl;
    std::cout << "3. Round Robin" << std::endl;
    std::cout << "4. Priority Scheduling" << std::endl;
    std::cout << "Choice: ";
    
    int algoChoice;
    std::cin >> algoChoice;
    
    if (algoChoice == 1) {
        FCFS scheduler(processes);
        scheduler.execute();
        scheduler.displayResults();
    } else if (algoChoice == 2) {
        SJF scheduler(processes);
        scheduler.execute();
        scheduler.displayResults();
    } else if (algoChoice == 3) {
        int quantum;
        std::cout << "Enter time quantum: ";
        std::cin >> quantum;
        
        RoundRobin scheduler(processes, quantum);
        scheduler.execute();
        scheduler.displayResults();
    } else if (algoChoice == 4) {
        Priority scheduler(processes);
        scheduler.execute();
        scheduler.displayResults();
    } else {
        std::cout << "Invalid choice!" << std::endl;
        return 1;
    }

    return 0;
}
