#include <iostream>
#include <vector>
#include <cstdint>
#include "algori.h"
#include "lab/calc.hpp"



/*
    mkdir build
    cd build
    每次编译一定要，因为有缓存
    cmake .. -DMY_CMAKE_BUILD_FLAGS=real   /   cmake .. 
    make 
*/

int main()
{
    ErrorInfo err;
    CalInterface("111111", err);
    std::cout << "err::errVec size: " << err.errVec.size() << std::endl;
    std::cout << "mean: " << lab::mean({1.0, 2.0, 3.0}) << std::endl;
    return 0;
}
