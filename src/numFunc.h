//
// Created by Dustin Tracy on 7/1/15.
//

#ifndef PROJECTEULER_NUMFUNC_H
#define PROJECTEULER_NUMFUNC_H

#include <iostream>
#include <vector>

template<class T>
class numFunc {
public:
    // Constructor that requires a single number
    numFunc(T &number) {
        setNumber(number);
    }

    // Sets the number
    void setNumber(T &z) {
        N = z;
    }

    // Creates a vector containing the fibonacci
    // series
    std::vector<T> Fibonacci() {
        std::vector<T> fib;
        fib.push_back(1);
        fib.push_back(2);

        int i = 2;
        while (fib[i - 1] + fib[i - 2] <= N) {
            fib.push_back(fib[i - 2] + fib[i - 1]);
            i++;
        }
        return fib;
    }
   
private:
    T N;
};

#endif //PROJECTEULER_NUMFUNC_H
