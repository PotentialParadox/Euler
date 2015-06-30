//
// Created by Dustin Tracy on 6/30/15.
//

#include <vector>
#include <iostream>
#include "Functions.h"

using namespace::std;


int main()
{
    int x = 10;
    std::vector<int> vectorfib = Fibonacci(x);
    vectorPrint(vectorfib);
    return 0;
}