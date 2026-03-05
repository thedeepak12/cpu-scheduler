CXX = g++
CXXFLAGS = -std=c++11 -I include
TARGET = scheduler
SOURCES = src/main.cpp src/core/Process.cpp \
          src/scheduler/FCFS.cpp src/scheduler/SJF.cpp \
          src/scheduler/RoundRobin.cpp src/scheduler/Priority.cpp \
          src/scheduler/SRTF.cpp src/utils/GanttChart.cpp \
          src/utils/InputHandler.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: all run clean
