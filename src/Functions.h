//
// Created by Dustin Tracy on 6/30/15.
//

#ifndef PROJECTEULER_FUNCTIONS_H
#define PROJECTEULER_FUNCTIONS_H
#include <vector>
#include <cmath>

template <class A>
A sum(std::vector<A> &list)
{
    A sumValue = 0;
    for (A i : list)
    {
        sumValue += i;
    }
    return sumValue;
}

template <class A>
A vectorPrint(std::vector<A> &list)
{
    for (A i : list)
    {
        std::cout << i << std::endl;
    }
}

template <class A>
std::vector<A> Fibonacci(A N)
{
    std::vector<A> fib;
    fib.push_back(1);
    fib.push_back(2);
    int i = 2;
    while (fib[i-1] + fib[i-2] <= N)
    {
        fib.push_back(fib[i-2] + fib[i-1]);
        i++;
    }
    return fib;
}

template <class A>
std::vector<A> evenFinder(std::vector<A> &list)
{
    std::vector<A> evenList;
    for (A i : list)
    {
        if (!(i % 2))
        {
            evenList.push_back(i);
        }
    }
    return evenList;
}

template <class A>
bool primeTest(A N)
{
    bool condition = 1;
    A i = 2;
    while (condition && (i <= (A)pow(N, 0.5)))
    {
        if (!(N % i))
        {
            condition = 0;
        }
        i++;
    }
    return condition;
}

#endif //PROJECTEULER_FUNCTIONS_H
