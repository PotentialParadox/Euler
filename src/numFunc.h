//
// Created by Dustin Tracy on 7/1/15.
//
// Construct with a number of any type, though
// not all functions will work with all types, i've been pretty lazy with the error
// messaging, so use your best judgment.
// Note that since this is a template class, it's fine for me to keep my functions in
// this file, though I could have attached it as a .tpp file via an include statement
// at the end

#ifndef PROJECTEULER_NUMFUNC_H
#define PROJECTEULER_NUMFUNC_H

#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>

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

    // The basic prime tester. It requires an argument since it is
    // used by the listPrimeFactor and primeFactorList functions.
    bool isPrime(T k){
        bool condition = 1;
        T i = 2;
        while ( condition && (i <= (T)pow(k, 0.5)))
        {
            if (!(k%i))
            {
                condition=0;
            }
            i++;
        }
        return condition;
    }

    // The basic prime tester.
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

    // Lists the prime factors of some positive number.
    std::vector<T> listPrimeFactors() {
        std::vector<T> primeList;
        T maxVal = N;
        if (maxVal < 0){
            std::cout << "For listPrimeFactors(), please provide a positive number" << std::endl;
        }
        for (T i = 2; i <= maxVal; ++i)
        {
            if (!(N % i) && isPrime(i))
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

    // Lists the prime factors of some positive number. Requires an argument
    // so as to be included in these functions.
    std::vector<T> listPrimeFactors(T k) {
        std::vector<T> primeList;
        T maxVal = k;
        if (maxVal < 0){
            std::cout << "For listPrimeFactors(), please provide a positive number" << std::endl;
        }
        for (T i = 2; i <= maxVal; ++i)
        {
            if (!(k % i) && isPrime(i))
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
            primeList.push_back(k);
        }
        return primeList;
    }

    // Tests whether the number is a palindrome
    bool palindromeTest(){
        bool condition = 1;
        std::ostringstream convert;
        convert << N;
        std::string numberString = convert.str();
        if (numberString.length() % 2)
        {
            for (unsigned int i = 0; i < (numberString.length() - 1) / 2; ++i)
            {
                if (numberString[i] != numberString[numberString.length() - 1 - i])
                {
                    condition = 0;
                }
            }
        }
        else
        {
            for (unsigned int i = 0; i < numberString.length() / 2; ++i)
            {
                if (numberString[i] != numberString[numberString.length() - 1 - i])
                {
                    condition = 0;
                }
            }
        }
        return condition;
    }

    // Sums the square of every number up to the number N. For example
    // if N is 3. 1 + 4 + 9 = 14.
    T sumofSquares(){
        T value = 0;
        for (int i = 1; i <= N; ++i)
        {
            value += pow(i, 2);
        }
        return value;
    }

    // Squares the sum of the numbers up to the number N. For example
    // if N is 3. (1 + 2 + 3)^2 = 36
    T squareofSums()
    {
        T value = 0;
        for (int i = 1; i <= N; ++i)
        {
            value += i;
        }
        value = pow(value, 2);
        return value;
    }

    // Counts the number of divisors
    T divisorCount()
    {
        T value = 0;
        if (N == 1)
        {
            value = 1;
        }
        else
        {
            for (int i = 1; i <= pow(N, 0.5); ++i)
            {
                if (!(N % i))
                {
                    value = value + 2;
                }
            }
        }
        return value;
    }

    T factorial()
    {
        if (N == 0)
        {
            return 0;
        }
        else
        {
            T value = 1;
            for (T i = 1; i <= N; ++i)
            {
                value *= i;
            }
            return value;
        }
    }

    T choose(T K)
    {
        T value = 1;
        // Divide the numerator by the larger of the two denominator terms, then make
        // a vector for the numbers that need to be multiplied for both the numerator
        // and denominator
        std::vector<T> numerator;
        std::vector<T> denominator;
        if (K >= N / 2)
        {
            for (T i = K + 1; i <= N; ++i)
            {
                numerator.push_back(i);
            }
            for (T i = 2; i <= N - K; ++i)
            {
                denominator.push_back(i);
            }
        }
        if (K < N / 2)
        {
            for (T i = N - K + 1; i <= N; ++i)
            {
                numerator.push_back(i);
            }
            for (T i = 2; i <= K; ++i)
            {
                denominator.push_back(i);
            }
        }

        // We now want to expand the numerator and denominators into a sorted list of
        // prime factors
        std::vector<T> numeratorexpanded;
        for (int i : numerator)
        {
            std::vector<T> expandedValues = listPrimeFactors(i);
            numeratorexpanded.insert(numeratorexpanded.end(), expandedValues.begin(),
                                     expandedValues.end());
        }
        std::sort(numeratorexpanded.begin(), numeratorexpanded.end());

        std::vector<T> denominatorexpanded;
        for (int i : denominator)
        {
            std::vector<T> expandedValues = listPrimeFactors(i);
            denominatorexpanded.insert(denominatorexpanded.end(),
                                       expandedValues.begin(), expandedValues.end());
        }
        std::sort(denominatorexpanded.begin(), denominatorexpanded.end());

        // We now begin canceling the factors, to do this we make a new numerator
        // vector for the cancled values and erase the canceld values from the
        // denominator vector
        std::vector<T> numeratorcanceled;
        for (T i : numeratorexpanded)
        {
            bool condition = 1;
            int iterator = 0;
            if (denominatorexpanded.empty())
            {
                numeratorcanceled.push_back(i);
            }
            while (condition && !(denominatorexpanded.empty()))
            {

                T dvalue = denominatorexpanded[iterator];
                if (i == dvalue)
                {
                    denominatorexpanded.erase(denominatorexpanded.begin() + iterator);
                    iterator++;
                    condition = 0;
                }
                if (i < dvalue)
                {
                    numeratorcanceled.push_back(i);
                    iterator++;
                    condition = 0;
                }
                if (iterator == (T)denominator.size())
                {
                    condition = 0;
                    iterator++;
                }
            }
        }

        // Finally we multiply the numerator values to together, then divide by the
        // denominator values

        for (T i : numeratorcanceled)
        {
            value *= i;
        }

        for (T i : denominatorexpanded)
        {
            value /= i;
        }

        return value;
    }


private:
    T N;
};

#endif //PROJECTEULER_NUMFUNC_H
