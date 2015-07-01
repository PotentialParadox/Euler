//
// Created by Dustin Tracy on 7/1/15.
//

#ifndef PROJECTEULER_VECFUNC_H
#define PROJECTEULER_VECFUNC_H

#include <vector>
#include <iostream>

template<class T>
class vecFunc {
public:
    vecFunc(std::vector<T> &list) {
        setVector(list);
    }

    // The constructor, requiring a vector
    void setVector(std::vector<T> &w) {
        list = w;
    }

    // Prints a vector
    void vectorPrint() {
        for (T i : list) {
            std::cout << i << std::endl;
        }
    }

    // Selects only the even numbers in a vector
    std::vector<T> evenFinder() {
        std::vector<T> evenList;
        for (T i : list) {
            if (!(i % 2)) {
                evenList.push_back(i);
            }
        }
        return evenList;
    }

    // Provides the max value in a vector
    T max() {
        T value = list[0];
        for (T i : list) {
            if (i > value) { value = i; }
        }
        return value;
    }


private:
    std::vector<T> list;

};

#endif //PROJECTEULER_VECFUNC_H
