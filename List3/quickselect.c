#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nrComp;
int nrSwap;

void insertSort(int  tab[],int start, int end){
    int i,j;
    int tmp;
    if(end - start >= 1){
        for(i = start+1; i <= end; i++ ){
            j = i;
            while(j > start ){
                if(tab[j] < tab[j-1]){
                    tmp = tab[j-1];
                    tab[j-1] = tab[j];
                    tab[j] = tmp;
                } else{ break;}
                j--;
            }
        }
    }
}

void medianOfMedians(int tab[],int start, int end){
    int n = end - start + 1;
    int tmp;
    if(n <=5){
        insertSort(tab,start,end);
        tmp = tab[start];
        tab[start] = tab[start + (n / 2)];
        tab[start + (n / 2)] = tmp;
    } else{
        int a = n / 5;
        int i;
        for(i = 0; i < a; i++){
            insertSort(tab,start + 5 * i, start + 4 + 5 * i);
        }
        if(5 * a < n){
            insertSort(tab,start + 5 * a, end);
        }
        for(i = 0; i < a; i++){
            tmp = tab[start + i];
            tab[start + i] = tab[start + 2 + (5 * i)];
            tab[start + 2 + (5 * i)] = tmp;
        }
        if(5 * a < n){
            tmp = tab[start + a];
            tab[start + a] = tab[start + ((5 * a) + n)/2];
            tab[start + ((5 * a) + n)/2] = tmp;
            a++;
        }
        medianOfMedians(tab,start,start + a-1);
    }
}

int partition(int tab[], int start, int end){
    medianOfMedians(tab,start,end);
    int i = start;
    int j,tmp;
    int key = tab[start];
    for(j = start + 1; j <= end ;j++){
        nrComp++;
        if(tab[j] < key){
            i++;
            nrSwap++;
            tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
        }
    }
    nrSwap++;
    tmp = tab[start];
    tab[start] = tab[i];
    tab[i] = tmp;
    return i;
}

void quickSort(int tab[], int start, int end){
    if( start < end) {
        int key = partition(tab, start, end);
        quickSort(tab, start, key - 1);
        quickSort(tab, key + 1, end);
    }
}

void addRand(int tab[], int size){
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        tab[i] =  rand();
    }
}

int main() {
    int *tab;
    srand(time(NULL));
    FILE *out;
    out = fopen("quickselect_stat.txt", "w");
    int i, j;
    for (i = 100; i <= 100000; i = i + 100) {
        nrComp = 0;
        nrSwap = 0;
        tab = malloc(i * sizeof(int));
        for (j = 0; j < 100; j++) {
            addRand(tab, i);
            quickSort(tab, 0, i - 1);
        }
        nrSwap = nrSwap / j;
        nrComp = nrComp / j;
        printf("%d\n", i);
        fprintf(out, "%d %d %d\n", i, nrComp, nrSwap);
        free(tab);
    }
    fclose(out);
}