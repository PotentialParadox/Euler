//
// Created by Dustin Tracy on 6/30/15.
//

#include <iostream>
#include <vector>
#include "vecFunc.h"

int main()
{
    std::vector<int> y;
    y.push_back(2);
    y.push_back(3);
    vecFunc<int> boo(y);
    boo.vectorPrint();
    std::cout << boo.max() << std::endl;
    return 0;
}