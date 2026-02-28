#ifndef GANTT_CHART_HPP
#define GANTT_CHART_HPP

#include <vector>
#include <string>

struct GanttEntry {
    int pid;
    int startTime;
    int endTime;

    GanttEntry(int p, int start, int end)
        : pid(p), startTime(start), endTime(end) {}
};

class GanttChart {
private:
    std::vector<GanttEntry> entries;

public:
    void addEntry(int pid, int startTime, int endTime);
    void display();
};

#endif
