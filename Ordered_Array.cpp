//
// Created by yorgo on 19/4/2021.
//

#include <iostream>
#include <ctime>
#include "Ordered_Array.h"
using namespace  std;


Ordered_Array::Ordered_Array(long n) : Unordered_Array(n) {
 //ftiaxnei oti ftiaxnei o unordered
}

Ordered_Array Ordered_Array::order(Unordered_Array arr, long n) {
    Ordered_Array newarr(n);
    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr.getVal(i).compare(arr.getVal(j)) < 0){
                string temp=arr.getVal(i);
                arr.setVal(i,arr.getVal(j));
                arr.setVal(j,temp);


                newarr.setVal(i,arr.getVal(i));

            }
        }
    }

    return newarr;

}
void Ordered_Array::show(Ordered_Array arr, long n) {
    for(int j=n-1;j>=0;j--){
        if (arr.getVal(j)!="") {
            cout <<"Word: "<< arr.getVal(j)<< endl;

        }
    }
}

void Ordered_Array::search(Ordered_Array arr, string *Q, long sum) {
    clock_t start;
    double duration;
    int num[1000];
    for(int & n : num){
        n=0;
    }
    start = clock(); //ksekinaei to xronometro
    for(int i=0;i<1000;i++){
        for (int j=0;j<sum;j++){
            if(Q[i] == arr.getVal(j)){
                num[i] += 1;

            }
        }

    }
    duration=(clock()-start/(double) CLOCKS_PER_SEC); // metraei poso ekane h ordered
    cout << "\n----------------------------ORDERED ARRAY----------------------------\n";
    for(int i=0;i<1000;i++){
        cout<<"Word: "<<Q[i]<<" , appears "<<num[i]<<" time(s)"<<endl;
    }
    cout<<"DURATION: "<<duration/1000<<endl;


}



