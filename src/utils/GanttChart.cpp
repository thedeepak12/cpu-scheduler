#include "../../include/utils/GanttChart.hpp"
#include <iostream>
#include <iomanip>

void GanttChart::addEntry(int pid, int startTime, int endTime) {
    entries.push_back(GanttEntry(pid, startTime, endTime));
}

void GanttChart::display() {
    std::cout << "\n=== Gantt Chart ===" << std::endl;

    std::cout << " ";
    for (const auto& entry : entries) {
        int width = entry.endTime - entry.startTime;

        for (int i = 0; i < width * 4; i++) {
            std::cout << "-";
        }
    }
    std::cout << std::endl;

    std::cout << "|";
    for (const auto& entry : entries) {
        int width = entry.endTime - entry.startTime;
        int spaces = width * 4 - 3;
        int leftPad = spaces / 2;
        int rightPad = spaces - leftPad;

        for (int i = 0; i < leftPad; i++) std::cout << " ";
        std::cout << "P" << entry.pid;
        for (int i = 0; i < rightPad; i++) std::cout << " ";
        std::cout << "|";
    }
    std::cout << std::endl;

    std::cout << " ";
    for (const auto& entry : entries) {
        int width = entry.endTime - entry.startTime;
        for (int i = 0; i < width * 4; i++) {
            std::cout << "-";
        }
    }
    std::cout << std::endl;

    std::cout << entries[0].startTime;
    for (const auto& entry : entries) {
        int width = entry.endTime - entry.startTime;
        int numDigits = std::to_string(entry.endTime).length();
        int spaces = width * 4 - numDigits;

        for (int i = 0; i < spaces; i++) std::cout << " ";
        std::cout << entry.endTime;
    }
    std::cout << std::endl;
}
