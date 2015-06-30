//
// Created by Dustin Tracy on 6/30/15.
//

#include "Math.h"

using namespace::std;

template <typename T>
T Math<T>::sum(vector<T> &list)
{
    T sumValue = 0;
    for (T i : list)
    {
        sumValue +=i;
    }
    return sumValue;
}
