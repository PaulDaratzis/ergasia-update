#include <iostream>
using namespace std;
#include <string>
#include<algorithm>
#include <fstream>
#include "Unordered_Array.h"
#include "Ordered_Array.h"
#include <cstdio>
#include <ctime>
#include <stdlib.h>



/*
 * Κάνω την λέξη να έχει μόνο μικρά γράμματα
 */
string lower(string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}
/*
 * Διαγράφω special chars απο τις
 */
string removePunctuation(string word) {

    word.erase(remove(word.begin(), word.end(), ':'), word.end());
    word.erase(remove(word.begin(), word.end(), ','), word.end());
    word.erase(remove(word.begin(), word.end(), '-'), word.end());
    word.erase(remove(word.begin(), word.end(), '.'), word.end());
    word.erase(remove(word.begin(), word.end(), '!'), word.end());
    word.erase(remove(word.begin(), word.end(), '?'), word.end());
    word.erase(remove(word.begin(), word.end(), ';'), word.end());
    word.erase(remove(word.begin(), word.end(), '_'), word.end());
    word.erase(remove(word.begin(), word.end(), '='), word.end());
    word.erase(remove(word.begin(), word.end(), '+'), word.end());
    word.erase(remove(word.begin(), word.end(), '/'), word.end());
    word.erase(remove(word.begin(), word.end(), '"'), word.end());
    word.erase(remove(word.begin(), word.end(), '&'), word.end());
    word.erase(remove(word.begin(), word.end(), '%'), word.end());
    word.erase(remove(word.begin(), word.end(), '%'), word.end());
    word.erase(remove(word.begin(), word.end(), '`'), word.end());
    word.erase(remove(word.begin(), word.end(), '^'), word.end());
    word.erase(remove(word.begin(), word.end(), '('), word.end());
    word.erase(remove(word.begin(), word.end(), ')'), word.end());
    word.erase(remove(word.begin(), word.end(), '['), word.end());
    word.erase(remove(word.begin(), word.end(), ']'), word.end());
    word.erase(remove(word.begin(), word.end(), '@'), word.end());
    word.erase(remove(word.begin(), word.end(), '#'), word.end());
    word.erase(remove(word.begin(), word.end(), '*'), word.end());
    word.erase(remove(word.begin(), word.end(), '~'), word.end());
    word.erase(remove(word.begin(), word.end(), '1'), word.end());
    word.erase(remove(word.begin(), word.end(), '2'), word.end());
    word.erase(remove(word.begin(), word.end(), '3'), word.end());
    word.erase(remove(word.begin(), word.end(), '4'), word.end());
    word.erase(remove(word.begin(), word.end(), '5'), word.end());
    word.erase(remove(word.begin(), word.end(), '6'), word.end());
    word.erase(remove(word.begin(), word.end(), '7'), word.end());
    word.erase(remove(word.begin(), word.end(), '8'), word.end());
    word.erase(remove(word.begin(), word.end(), '9'), word.end());
    word.erase(remove(word.begin(), word.end(), '0'), word.end());
    word.erase(remove(word.begin(), word.end(), '\n'), word.end());
    word.erase(remove(word.begin(), word.end(), ' '), word.end());

    return word;


}
  int num_of_rows()
  {
    fstream file1;
     string filename="test.txt";
     long long int sum=0;
     string WORD;
     file1.open(filename);
    while(!file1.eof())
    {
        file1>>WORD;
        sum++;
    }
    //cout<<sum<<endl;
    return sum;
 }

int main() {


    fstream file1;
    /*string filename="test.txt";
    long long int sum=0;
    string WORD;
    //file.open("test.txt",ios::in);
    file1.open(filename);
    while(!file1.eof())
    {
        file1>>WORD;
        sum++;
    }
    //cout<<sum<<endl;*/
    int SUM=num_of_rows();
    string Q[1000];
    Unordered_Array un_arr(SUM);


    int num[SUM];

    for (int x=0;x<SUM;x++){
        num[x]=0;
    }

    fstream file;
    string filename="test.txt";
    string word;

    file.open(filename);
    if (!file) {
        cerr << "Unable to open file test.txt";
        exit(1);
    }
    int i=0;
    while (file >> word && i<SUM)
    {

        string tempword = removePunctuation(lower(word)); // ΛΕΞΗ ΧΩΡΙΣ ΣΗΜΕΙΟ ΣΤΙΞΗΣ ΚΑΙ ΜΙΚΡΑ ΓΡΑΜΜΑΤΑ
        un_arr.setVal(i, tempword);
        i++;


    }
    Unordered_Array temp(SUM); //προσωρινα για να μην χαλασω τον un_arr
    for(int a=0;a<SUM;a++){
        temp.setVal(a, un_arr.getVal(a));
    }

    Ordered_Array temparr(SUM); // το εφτιαξα αυτο μονο και μονο για να καλεσω την order που επιστρεφει
                                // ετοιμο τον ταξινομημενο πινακα
    Ordered_Array or_arr = temparr.order(temp,SUM);

    //παιρνω 1000 τυχαιες λεξεις απο τον un_arr
    int q=0;
    while(q<1000){
        string temp=un_arr.getVal(rand() % SUM);
        if (temp!="") {
            Q[q] =temp;
            //cout << Q[q] << endl;
            q++;
        }

    }
    //αυξουσα ταξινομηση του Q
    for (int i=0;i<1000;i++){
        for(int j=i+1;j<1000;j++){
            if(Q[i].compare(Q[j]) > 0){
                string temp=Q[j];
                Q[j]=Q[i];
                Q[i]=temp;


            }
        }
    }


    un_arr.search(un_arr,Q,SUM);
    or_arr.search(or_arr,Q,SUM);








}

