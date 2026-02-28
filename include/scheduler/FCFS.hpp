#ifndef FCFS_HPP
#define FCFS_HPP

#include <vector>
#include "../core/Process.hpp"
#include "../utils/GanttChart.hpp"

class FCFS {
private:
    std::vector<Process> processes;
    GanttChart gantt;

public:
    FCFS(std::vector<Process> procs);
    void execute();
    void displayResults();
};

#endif
