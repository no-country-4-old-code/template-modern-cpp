#include "fizzbuzz.h"
#include <string>

/**
 * @brief Maps an integer to a FizzBuzz string.
 *
 * This function takes an unsigned integer as input and returns a string based
 * on the FizzBuzz rules:
 * - "FIZZ" if the number is divisible by 3.
 * - "BUZZ" if the number is divisible by 5.
 * - "FIZZBUZZ" if the number is divisible by both 3 and 5.
 * - The number itself as a string if it's divisible by neither.
 *
 * @param number The integer to be mapped to a FizzBuzz string.
 * @return std::string The corresponding FizzBuzz string representation.
 */
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