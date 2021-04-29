//
// Created by yorgo on 19/4/2021.
//

#ifndef ERGASIA_UNORDERED_ARRAY_H
#define ERGASIA_UNORDERED_ARRAY_H
using namespace std;
#include <string>

class Unordered_Array{

private:
    string *arr{};

public:
    explicit Unordered_Array(long n);
    void setVal(long i,string val){
        arr[i]=val;
    }
    string getVal(long i){
        return arr[i];
    }
    void show(Unordered_Array arr,long sum);
    void search(Unordered_Array arr,string Q[],long sum);

};


#endif //ERGASIA_UNORDERED_ARRAY_H
