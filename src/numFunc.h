//
// Created by Dustin Tracy on 7/1/15.
//

#ifndef PROJECTEULER_NUMFUNC_H
#define PROJECTEULER_NUMFUNC_H

#include <iostream>
#include <vector>
#include <math.h>

template<class T>
class numFunc {
public:
    // Constructor that requires a single number
    numFunc(T number) {
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

    // The basic prime tester
    bool isPrime(){
        bool condition = 1;
        T i = 2;
        while ( condition && (i <= (T)pow(N, 0.5)))
        {
            if (!(N%i))
            {
                condition=0;
            }
            i++;
        }
        return condition;
    }

    std::vector<T> listPrimeFactors() {
        std::vector<T> primeList;
        T maxVal = N;
        for (long long int i = 2; i <= maxVal; ++i)
        {
            if (!(N % i) && isPrime())
            {
                while (!(maxVal % i))
                {
                    maxVal = maxVal / i;
                    primeList.push_back(i);
                }
            }
        }
        if (primeList.empty())
        {
            primeList.push_back(N);
        }
        return primeList;
    }


private:
    T N;
};

#endif //PROJECTEULER_NUMFUNC_H
