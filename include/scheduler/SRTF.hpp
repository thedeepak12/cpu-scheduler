#ifndef SRTF_HPP
#define SRTF_HPP

#include <vector>
#include "../core/Process.hpp"
#include "../utils/GanttChart.hpp"

class SRTF {
private:
    std::vector<Process> processes;
    GanttChart gantt;
    
public:
    SRTF(std::vector<Process> procs);
    void execute();
    void displayResults();
};

#endif
