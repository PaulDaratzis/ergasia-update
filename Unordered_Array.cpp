//
// Created by yorgo on 19/4/2021.
//

#include "Unordered_Array.h"
using namespace std;
#include <string>
#include<algorithm>
#include <iostream>
#include <ctime>


Unordered_Array::Unordered_Array(long n) {
    long rows=n;
    arr=new string[rows];
}

void Unordered_Array::show(Unordered_Array arr,long sum) {
    for(int j=0;j<sum;j++){
        if (arr.getVal(j)!="") {
            cout <<"Word: "<< arr.getVal(j)<< endl;
        }
    }

}

void Unordered_Array::search(Unordered_Array arr, string *Q, long sum) {
    clock_t start; //ρολοι
    double duration; //διαρκεια
    int num[1000]; //πινακας με το πληθος της καθε λεξης
    for(int & n : num){
        n=0; //βαζω παντου 0
    }
    start = clock(); //ksekinaei to xronometro
    for(int i=0;i<1000;i++){
        for (int j=0;j<sum;j++){
            if(Q[i] == arr.getVal(j)){
                num[i] += 1;
            }
        }

    }
    duration=(clock()-start/(double) CLOCKS_PER_SEC); // metraei poso ekane h unordered
    cout << "\n----------------------------UNORDERED ARRAY----------------------------\n";
    for(int i=0;i<1000;i++){
        cout<<"Word: "<<Q[i]<<" , appears "<<num[i]<<" time(s)"<<endl;
    }
    cout<<"DURATION: "<<duration/1000<<endl;



}


