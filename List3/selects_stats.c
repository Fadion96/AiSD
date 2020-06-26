#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int nrComp;
int nrComp2;

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
        nrComp2++;
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

int randPartition(int tab[], int start, int end){
    int i = start;
    int j,tmp;
    int pivot_index = start + rand() % (end - start + 1);
    tmp = tab[start];
    tab[start] = tab[pivot_index];
    tab[pivot_index] = tmp;
    int key = tab[start];
    for(j = start + 1; j <= end ;j++){
        nrComp++;
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

int main() {
    int *tab,*tab2;
    srand(time(NULL));
    FILE *out;
    FILE *out2;
    out = fopen("randomselect_stat.txt","w");
    out2 = fopen("select_stat.txt","w");
    int i,j,avg,avg2,min,min2,max,max2,pos;
    for( i = 5 ; i <= 500; i++){
        tab = malloc(i * sizeof(int));
        tab2 = malloc(i * sizeof(int));
        avg = 0;
        avg2 = 0;
        max = 0;
        max2 = 0;
        min = INT32_MAX;
        min2 = INT32_MAX;
        for (j = 0; j < 1000; j++){
            nrComp = 0;
            nrComp2 = 0;
            addToSize(tab, i);
            for(int x = 0; x < i; x++){
                tab2[x] = tab[x];
            }
            pos = rand()%i;
            randSelect(tab,0,i - 1,pos);
            selectAlg(tab2,0,i - 1,pos);
            avg+=nrComp;
            avg2+=nrComp2;
            if(nrComp > max){
                max = nrComp;
            }
            else if(nrComp < min){
                min = nrComp;
            }
            if(nrComp2 > max2){
                max2 = nrComp2;
            }
            else if(nrComp2 < min2){
                min2 = nrComp2;
            }
        }
        avg /= j;
        avg2 /= j;
        printf("%d\n",i);
        fprintf(out,"%d %d %d %d\n",i,min,avg,max);
        fprintf(out2,"%d %d %d %d\n",i,min2,avg2,max2);
        free(tab);
        free(tab2);
    }
    fclose(out);
}