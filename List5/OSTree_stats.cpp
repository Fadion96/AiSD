#include <fstream>
#include <iostream>
#include <algorithm>
#include "Tree.h"

using namespace std;

int main(){
    ofstream out("tree_os_stat.txt");
    int i,j,k,l,compares,min,max;
    double avg;
    int *tab;
    for(i = 5; i <= 500; i++){
        tab = new int[i];
        for(k = 0; k < i; k++){
            tab[k] = k + 1;
        }
        Tree tree2;
        max = 0;
        min = INT32_MAX;
        avg = 0;
        compares = 0;
        for(k = 0; k < i; k++){
            tree2.insert(tab[k]);
        }
        for(k = 1; k <= i; k++){
            compares = tree2.OSSelect2(k);
            if(compares < min){
                min = compares;
            } else if(compares > max){
                max = compares;
            }
            avg += compares;
        }
        for(j = 1; j < 1000; j++){
            Tree tree;
            random_shuffle(&tab[0],&tab[i]);
            compares = 0;
            for(l = 0; l < i; l++){
                tree.insert(tab[l]);
            }
            for(l = 1; l <= i; l++){
                compares = tree.OSSelect2(l);
                if(compares < min){
                    min = compares;
                } else if(compares > max){
                    max = compares;
                }
                avg += compares;
            }
        }
        avg /=(double)(i*1000);
        cout<<i<<endl;
        out<<i<<" "<<min<<" "<<avg<<" "<<max<<endl;
    }
    out.close();
}