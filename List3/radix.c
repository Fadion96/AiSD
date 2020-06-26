#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long long nrPut;

void printTab(int tab[], int start, int end){
    for(int i = start; i < end; i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}

int getMax(int tab[], int size){
    int max = 0;
    for(int i = 0; i < size; i++){
        if( tab[i] > max){
            max = tab[i];
        }
    }
    return max;
}

void countSort(int tab[], int size, int exp, int base){
    int i;
    int c[base];
    int b[size];
    for(i = 0; i < base; i++){
        c[i]=0;
    }
   printTab(c,0,10);
    for(i = 0; i < size; i++){
        c[(tab[i]/exp)%base]++;
    }
   printTab(c,0,10);
    for(i = 1; i < base; i++){
        c[i] += c[i - 1];
    }
   printTab(c,0,10);
    for(i = size - 1; i >= 0; i--){
        b[c[(tab[i] / exp) % base] - 1] = tab[i];
        c[(tab[i] / exp) % base]--;
    }
    for(i = 0; i < size; i++){
        tab[i] = b[i];
        nrPut++;
    }
}

void radixSort(int tab[], int size){
    int m = getMax(tab,size);
    double base = ceil(sqrt(m+1));
    for(int i = 1; m / i > 0; i *= base){
        countSort(tab,size,i,m+1);
        
    }
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

int main(int argc, char * argv[]) {
    if(argc <= 2){
        int *tab;
        srand(time(NULL));
        FILE *out;
        out = fopen("radix_stat.txt","w");
        int i,j;
        for( i = 100 ; i <= 10000; i= i + 100){
            nrPut=0;
            tab = malloc(i * sizeof(int));
            for (j = 0; j < 100; j++){
                addDec(tab, i);
                radixSort(tab,i);
            }
            nrPut=nrPut/j;
            printf("%d\n",i);
            fprintf(out,"%d %lli \n",i,nrPut);
            free(tab);
        }
        fclose(out);
    }
    else{
        int op;
        int size;
        srand(time(NULL));
        op = strtol(argv[1],NULL,10);
        size = strtol(argv[2],NULL,10);
        if(size > 0){
            int * tab;
            tab = malloc(size*sizeof(int));
            switch (op){
                case 1:
                    addRand(tab,size);
                    break;
                case 2:
                    addDec(tab,size);
                    break;
                default:
                    printf("Wrong argument \n");
                    printf("Usage: \n");
                    printf("./radix1 <1 - random sequence, 2 - descreasing sequence> <number of elements (positive integer)> ");
                    return 0;
            }
            printTab(tab,0,size);
            printf("\n");
            radixSort(tab,size);
            printTab(tab,0,size);
            free(tab);
        } else{
            printf("Wrong argument \n");
            printf("Usage: \n");
            printf("./radix1 <1 - random sequence, 2 - descreasing sequence> <number of elements (positive integer)> ");
            return 0;
        }
    }
}