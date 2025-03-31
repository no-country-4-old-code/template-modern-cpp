#pragma once
#include <iostream>

class PrettyPrint {
   private:
    const char* name;

   public:
    PrettyPrint(const char* _name) : name{_name} {
    }

    void printName() const;

    template <typename... ARGS>
    static void print(ARGS... args) {
        ((std::cout << args << " "), ...);
        std::cout << "\n";
    }
};

auto factorial(unsigned int number) -> unsigned int;