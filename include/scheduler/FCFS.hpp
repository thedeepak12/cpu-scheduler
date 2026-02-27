#ifndef FCFS_HPP
#define FCFS_HPP

#include <vector>
#include "../core/Process.hpp"

class FCFS {
private:
    std::vector<Process> processes;

public:
    FCFS(std::vector<Process> procs);
    void execute();
    void displayResults();
};

#endif
