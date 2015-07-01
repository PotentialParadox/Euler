//
// Created by Dustin Tracy on 7/1/15.
//

#ifndef PROJECTEULER_VECFUNC_H
#define PROJECTEULER_VECFUNC_H

#include <vector>

template<class T>
class vecFunc {
public:
    vecFunc(std::vector<T> &list) {
        setVector(list);
    }

    void setVector(std::vector<T> &w) {
        list = w;
    }
   
    void vectorPrint()

private:
    std::vector<T> list;

};

#endif //PROJECTEULER_VECFUNC_H
