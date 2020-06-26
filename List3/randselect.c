#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printTab(int tab[], int start, int end){
    for(int i = start; i < end; i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}

int randPartition(int tab[], int start, int end){
    int i = start;
    int j,tmp;
    int pivot_index = start + rand() % (end - start + 1);
    tmp = tab[start];
    tab[start] = tab[pivot_index];
    tab[pivot_index] = tmp;
    int key = tab[start];
    for(j = start + 1; j <= end ;j++){
        if(tab[j] < key){
            i++;
            tmp = tab[j];
            tab[j] = tab[i];
            tab[i] = tmp;
        }
    }
    tmp = tab[start];
    tab[start] = tab[i];
    tab[i] = tmp;
    return i;
}
void quickSort(int tab[], int start, int end) {
    if (start < end) {
        int key = randPartition(tab, start, end);
        quickSort(tab, start, key - 1);
        quickSort(tab, key + 1, end);
    }
}

int randSelect(int tab[], int start, int end, int i){
    int r,k;
    if(start == end){
        return tab[start];
    }
    r = randPartition(tab,start,end);
    k = r - start ;
    if(i == k){
        return tab[r];
    }
    else if(i < k){
        return randSelect(tab,start,r - 1, i);
    }
    else{
        return randSelect(tab,r, end, i - k);
    }
}

void shuffle(int tab[], int size){
    int tmp;
    int random;
    for(int i = 0; i < size; i++){
        random = (5*rand())%size;
        random = random < 0 ? random + size : random;
        tmp = tab[i];
        tab[i] = tab[random];
        tab[random] = tmp;
    }
}

void addToSize(int tab[], int size){
    for(int i = 0; i < size; i++){
        tab[i] = size - i;
    }
    shuffle(tab,size);
}

void addRand(int tab[], int size){
    for(int i = 0; i < size; i++){
        tab[i] =  rand();
    }
}

int main(int argc, char * argv[]) {
    if(argc <= 3){
        printf("Usage: \n");
        printf("./randselect1 <1 - random sequence, 2 - 1 to number of elements sequence> <number of elements (positive integer)> <position [1-n]>.");
        return 0;
    }
    else{
        int op;
        int size;
        int pos;
        srand(time(NULL));
        op = strtol(argv[1],NULL,10);
        size = strtol(argv[2],NULL,10);
        pos = strtol(argv[3],NULL,10);
        if(size > 0){
            int * tab;
            tab = malloc(size*sizeof(int));
            switch (op){
                case 1:
                    addRand(tab,size);
                    break;
                case 2:
                    addToSize(tab,size);
                    break;
                default:
                    printf("Wrong argument \n");
                    printf("Usage: \n");
                    printf("./randselect1 <1 - random sequence, 2 - 1 to number of elements sequence> <number of elements (positive integer)> <position [1-n]>.");
            }
            if(pos > 0 && pos <= size){
                printTab(tab,0,size);
                printf("Pos %d : %d\n",pos,randSelect(tab,0,size - 1,pos-1));
                printf("Press key to sort array:");
                getchar();
                quickSort(tab,0,size - 1);
                printTab(tab,0,size);
            } else{
                printf("Wrong argument \n");
                printf("Usage: \n");
                printf("./randselect1 <1 - random sequence, 2 - 1 to number of elements sequence> <number of elements (positive integer)> <position [1-n]>.");
            }

            free(tab);
        } else{
            printf("Wrong argument \n");
            printf("Usage: \n");
            printf("./randselect1 <1 - random sequence, 2 - 1 to number of elements sequence> <number of elements (positive integer)> <position [1-n]>.");
            return 0;
        }
    }
}