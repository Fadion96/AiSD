#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"


long long nrComp;
long long nrSwap;


void printTab(int tab[], int start, int end){
    for(int i = start; i < end; i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}

void addDec(int tab[], int size){
    for(int i = 0; i < size; i++){
        tab[i] = size - i;
    }
}

void addRand(int tab[], int size){
    for(int i = 0; i < size; i++){
        tab[i] =  rand();
    }
}

void insertSort(int  tab[],int start, int end, int debug){
    int i,j;
    int tmp;
    if(end - start >= 1){
        for(i = start+1; i <= end; i++ ){
            j = i;
            while(j > start ){
                if(debug){
                    printf("Comparing %d %d\n",tab[j],tab[j-1]);
                    
                }
                else{
                    nrComp++;
                }
                if(tab[j] < tab[j-1]){
                    if(debug){
                        printf("Swapping %d %d\n",tab[j],tab[j-1]);
                    }
                    else{
                        nrSwap++;
                    }
                    tmp = tab[j-1];
                    tab[j-1] = tab[j];
                    tab[j] = tmp;
                } else{ break;}
                j--;
            }
        }
    }
}


void merge(int tab[],int start, int middle, int end, int debug){
    int a, b,size;
    int i = 0;
    int j = 0;
    size = end - start + 1;
    int * tmp;
    tmp = malloc(size * sizeof(int));
    a = start;
    b = middle + 1;
    while(a <= middle && b <= end){
        if(debug){
            printf("Comparing %d %d\n",tab[a],tab[b]);
        }
        else{
            nrComp++;
        }
        if(tab[a] <= tab[b]){
            if(debug){
                printf("Putting %d \n",tab[a]);
            }
            else{
                nrSwap++;
            }
            tmp[i++]= tab[a++];
        } else{
            if(debug){
                printf("Putting %d \n",tab[b]);
            }
            else{
                nrSwap++;
            }
            tmp[i++] = tab[b++];
        }
    }
    if(a - 1 == middle){
        while(b <= end){
            if(debug){
                printf("Putting %d \n",tab[b]);
            }
            else{
                nrSwap++;
            }
            tmp[i++] = tab[b++];
        }
    } else if (b - 1 == end){
        while(a <= middle){
            if(debug){
                printf("Putting %d \n",tab[a]);
            }
            else{
                nrSwap++;
            }
            tmp[i++] = tab[a++];
        }
    }
    for(i = start; i <= end; i++){
        tab[i] = tmp[j++];
    }
    free(tmp);
}

void mergeSort(int tab[], int start, int end, int debug){
    int middle = (start + end) / 2;
    if(start<end){
        mergeSort(tab, start, middle, debug);
        mergeSort(tab, middle + 1, end, debug);
        merge(tab, start, middle, end, debug);
   }
}

int partition(int tab[], int start, int end, int debug){
    int key = tab[start];
    int i = start;
    int j,tmp;
    for(j = start + 1; j <= end ;j++){
        if(debug){
            printf("Comparing %d %d\n",tab[j],key);
        }
        else{
            nrComp++;
        }        
        if(tab[j] < key){
            i++;
            if(debug){
                printf("Swapping %d %d\n",tab[j],tab[i]);
            }
            else{
                nrSwap++;
            }
            tmp = tab[j];
            tab[j] = tab[i];
            tab[i] = tmp;
        }
    }
    if(debug){
        printf("Swapping %d %d\n",tab[start],tab[i]);
    }
    else{
        nrSwap++;
    }    
    tmp = tab[start];
    tab[start] = tab[i];
    tab[i] = tmp;
    return i;
}

void quickSort(int tab[], int start, int end, int debug){
    if( start < end) {
        int key = partition(tab, start, end, debug);
        quickSort(tab, start, key - 1, debug);
        quickSort(tab, key + 1, end, debug);
    }
}

void mergeInsertSort(int tab[], int start, int end, int debug){
    if(end - start <= 10){
        insertSort(tab, start, end, debug);
    } else{
        int middle = (start + end) / 2;
        if(start<end){
            mergeSort(tab,start,middle, debug);
            mergeSort(tab,middle + 1,end, debug);
            merge(tab,start,middle,end, debug);
        }
    }
}

void quickInsertSort(int tab[], int start, int end, int debug){
    if(end - start <= 10){
        insertSort(tab, start, end, debug);
    }
    else {
        if( start < end) {
            int key = partition(tab, start, end, debug);
            quickSort(tab, start, key - 1, debug);
            quickSort(tab, key + 1, end, debug);
        }
    }
}

void dualPivotQuickSort(int tab[], int start, int end, int debug) {
    if(start < end){
        int p1, p2, tmp;
        if(debug){
            printf("Comparing %d %d\n",tab[start],tab[end]);
        }
        else{
            nrComp++;
        }
        if(tab[start] >= tab[end]){
            if(debug){
                printf("Swapping %d %d\n",tab[start],tab[end]);
            }
            else{
                nrSwap++;
            }
            tmp = tab[start];
            tab[start] = tab[end];
            tab[end] =  tmp;
        }
        p1 = tab[start];
        p2 = tab[end];
        int l = start + 1;
        int k = start + 1;
        int g = end - 1;
        while(k<=g){
            if(debug){
                printf("Comparing %d %d\n",tab[k],p1);
            }
            else{
                nrComp++;
            }
            if(tab[k] < p1){
                if(debug){
                    printf("Swapping %d %d\n",tab[k],tab[l]);
                }
                else{
                    nrSwap++;
                }
                tmp = tab[k];
                tab[k] = tab[l];
                tab[l] =  tmp;
                l++;
            } else {
                if(debug){
                    printf("Comparing %d %d\n", tab[k], p2);
                }
                else{
                    nrComp++;
                }
                if (tab[k] > p2) {
                    while (tab[g] > p2) {
                        g--;
                    }
                    if(debug){
                        printf("Swapping %d %d\n",tab[k],tab[g]);
                    }
                    else{
                        nrSwap++;
                    }
                    tmp = tab[k];
                    tab[k] = tab[g];
                    tab[g] = tmp;
                    g--;
                    if(debug){
                        printf("Comparing %d %d\n",tab[k],p1);
                    }
                    else{
                        nrComp++;
                    }
                    if (tab[k] < p1) {
                        if(debug){
                            printf("Swapping %d %d\n",tab[k],tab[l]);
                        }
                        else{
                            nrSwap++;
                        }
                        tmp = tab[k];
                        tab[k] = tab[l];
                        tab[l] = tmp;
                        l++;
                    }
                }
            }
            k++;
        }
        l--;
        g++;
        if(debug){
            printf("Swapping %d %d\n",tab[start],tab[l]);
        }
        else{
            nrSwap++;
        }
        tmp = tab[start];
        tab[start] = tab[l];
        tab[l] =  tmp;
        if(debug){
            printf("Swapping %d %d\n",tab[end],tab[g]);
        }
        else{
            nrSwap++;
        }
        tmp = tab[end];
        tab[end] = tab[g];
        tab[g] = tmp;
        dualPivotQuickSort(tab,start,l-1, debug);
        dualPivotQuickSort(tab,l+1,g-1, debug);
        dualPivotQuickSort(tab,g+1,end, debug);
    }
}