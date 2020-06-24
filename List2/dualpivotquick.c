#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./header/sorts.h"

extern long long nrComp;
extern long long nrSwap;

int main(int argc, char * argv[]) {
    if(argc <= 2){
        int *tab;
        srand(time(NULL));
        FILE *out;
        out = fopen("dualpivotquick_stat.txt","w");
        int i,j;
        for( i = 100 ; i <= 1000; i= i + 100){
            nrComp=0;
            nrSwap=0;
            tab = malloc(i * sizeof(int));
            for (j = 0; j < 100; j++){
                addRand(tab, i);
                dualPivotQuickSort(tab,0,i - 1, 0);
            }
            nrSwap=nrSwap/j;
            nrComp=nrComp/j;
            printf("%d\n",i);
            fprintf(out,"%d %d %d\n",i,nrComp,nrSwap);
            free(tab);
        }
        fclose(out);
    }
    else{
        int op;
        int size;
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
                    printf("./quick <1 - random sequence, 2 - descreasing sequence> <number of elements (positive integer)> ");
                    return 0;
            }
            printTab(tab,0,size);
            dualPivotQuickSort(tab,0,size - 1, 1);
            printTab(tab,0,size);
            free(tab);
        } else{
            printf("Wrong argument \n");
            printf("Usage: \n");
            printf("./quick <1 - random sequence, 2 - descreasing sequence> <number of elements (positive integer)> ");
            return 0;
        }
    }
}