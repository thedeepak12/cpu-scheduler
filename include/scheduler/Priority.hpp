#ifndef PRIORITY_HPP
#define PRIORITY_HPP

#include <vector>
#include "../core/Process.hpp"
#include "../utils/GanttChart.hpp"

class Priority {
private:
    std::vector<Process> processes;
    GanttChart gantt;

public:
    Priority(std::vector<Process> procs);
    void execute();
    void displayResults();
};

#endif
