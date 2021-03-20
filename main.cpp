
#include <exception>
#include <iostream>

#include "HydraulicLib/NetworkSolve.h"

int main() {
    try {
        NetworkSolve();
    } catch (const std::exception &exception) {
        std::cerr << exception.what() << '\n';
        throw;
    }
    return 0;
}