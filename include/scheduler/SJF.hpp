#ifndef SJF_HPP
#define SJF_HPP

#include <vector>
#include "../core/Process.hpp"
#include "../utils/GanttChart.hpp"

class SJF {
private:
    std::vector<Process> processes;
    GanttChart gantt;

public:
    SJF(std::vector<Process> procs);
    void execute();
    void displayResults();
};

#endif
