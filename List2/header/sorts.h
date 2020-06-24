#ifndef HEADER_SORTS_H
#define HEADER_SORTS_H

void printTab(int tab[], int start, int end);
void addDec(int tab[], int size);
void addRand(int tab[], int size);
void insertSort(int  tab[],int start, int end, int debug);
void merge(int tab[],int start, int middle, int end, int debug);
void mergeSort(int tab[], int start, int end, int debug);
int partition(int tab[], int start, int end, int debug);
void quickSort(int tab[], int start, int end, int debug);
void mergeInsertSort(int tab[], int start, int end, int debug);
void quickInsertSort(int tab[], int start, int end, int debug);
void dualPivotQuickSort(int tab[], int start, int end, int debug);


long long nrComp;
long long nrSwap;

#endif //HEADER_SORTS_H
