//
// Created by yorgo on 19/4/2021.
//

#ifndef ERGASIA_ORDERED_ARRAY_H
#define ERGASIA_ORDERED_ARRAY_H
#include "Unordered_Array.h"

class Ordered_Array : public Unordered_Array{
private :
    //long n;
public:

    explicit Ordered_Array(long n);
    Ordered_Array order(Unordered_Array arr, long n);

    void show(Ordered_Array arr, long n);

    void search(Ordered_Array arr, string *Q, long sum);
};
#endif //ERGASIA_ORDERED_ARRAY_H
