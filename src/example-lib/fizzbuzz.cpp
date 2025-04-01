#include "fizzbuzz.h"
#include <iostream>
#include <string>

const char* map_to_fizz_buzz(unsigned int number) {
    std::string result{};

    if (number % 3 == 0) {
        result.append("FIZZ");
    }

    if (number % 5 == 0) {
        result.append("BUZZ");
    }

    if (result.size() == 0) {
        result.append(std::to_string(number));
    }

    return result.c_str();
}