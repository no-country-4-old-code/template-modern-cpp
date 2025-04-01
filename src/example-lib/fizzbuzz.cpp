#include "fizzbuzz.h"
#include <string>

std::string map_to_fizz_buzz(unsigned int number) {
    std::string result{};
    const int   fizz = 3;
    const int   buzz = 5;

    if (number % fizz == 0) {
        result.append("FIZZ");
    }

    if (number % buzz == 0) {
        result.append("BUZZ");
    }

    if (result.empty()) {
        result.append(std::to_string(number));
    }

    return result;
}