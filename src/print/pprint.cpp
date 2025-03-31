#include "pprint.h"

#include <iostream>

void PrettyPrint::printName() const {
    std::cout << "NAME: " << this->name << "\n";
}

auto factorial(unsigned int number) -> unsigned int {
    if (number == 0) {
        return 0;
    }

    return number <= 1 ? number : factorial(number - 1) * number;
}
