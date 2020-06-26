#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printTab(int tab[], int start, int end){
    for(int i = start; i < end; i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}


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
        if(tab[j] < key){
            i++;
            tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
        }
    }
    tmp = tab[start];
    tab[start] = tab[i];
    tab[i] = tmp;
    return i;
}


int selectAlg(int tab[], int start, int end, int i){
    int r,k;
    if(start == end){
        return tab[start];
    }
    r = partition(tab,start,end);
    printTab(tab,start,end);
    k = r - start;
    if(i == k){
        return tab[r];
    }
    else if(i < k){
        return selectAlg(tab,start,r - 1, i);
    }
    else{
        return selectAlg(tab,r, end, i - k);
    }
}

void quickSort(int tab[], int start, int end) {
    if (start < end) {
        int key = partition(tab, start, end);
        quickSort(tab, start, key - 1);
        quickSort(tab, key + 1, end);
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
        printf("./select <1 - random sequence, 2 - 1 to number of elements sequence> <number of elements (positive integer)> <position [1-n]>.");
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
                    printf("./select <1 - random sequence, 2 - 1 to number of elements sequence> <number of elements (positive integer)> <position [1-n]>.");
            }
            if(pos > 0 && pos <= size){
                printTab(tab,0,size);
                printf("Pos %d : %d\n",pos,selectAlg(tab,0,size - 1,pos-1));
                printTab(tab,0,size);
                printf("Press key to sort array:");
                getchar();
                quickSort(tab,0,size - 1);
                printTab(tab,0,size);
            } else{
                printf("Wrong argument \n");
                printf("Usage: \n");
                printf("./select <1 - random sequence, 2 - 1 to number of elements sequence> <number of elements (positive integer)> <position [1-n]>.");
            }
            free(tab);
        } else{
            printf("Wrong argument \n");
            printf("Usage: \n");
            printf("./select <1 - random sequence, 2 - 1 to number of elements sequence> <number of elements (positive integer)> <position [1-n]>.");
            return 0;
        }
    }
}

