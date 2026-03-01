#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <vector>
#include "../core/Process.hpp"

class InputHandler {
public:
    static std::vector<Process> readFromConsole();
    static std::vector<Process> getDefaultData();
};

#endif
