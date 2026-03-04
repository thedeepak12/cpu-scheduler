#ifndef ROUND_ROBIN_HPP
#define ROUND_ROBIN_HPP

#include <vector>
#include <queue>
#include "../core/Process.hpp"
#include "../utils/GanttChart.hpp"

class RoundRobin {
private:
    std::vector<Process> processes;
    GanttChart gantt;
    int timeQuantum;

public:
    RoundRobin(std::vector<Process> procs, int quantum);
    void execute();
    void displayResults();
};

#endif
