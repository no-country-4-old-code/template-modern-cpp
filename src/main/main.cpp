#include <iostream>
#include "build-info.h"

/**
 * @file main.cpp
 * @brief Provides stuff for my great program.
 */
int main() {
    namespace info = build::info;
    std::cout << "Start " << info::projectname << " v" << info::version
              << " from #" << info::hash << "\n";
}