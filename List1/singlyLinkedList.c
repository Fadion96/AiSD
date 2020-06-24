#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

typedef struct LIST{
    struct LIST *next;
    int key;
}LIST;

void add (LIST **head, int key){
    LIST *new;
    LIST *tmp;
    new = (LIST *)malloc(sizeof(struct LIST));
    new->key = key;
    new->next = NULL;

    if(*head == NULL){
        *head = new;
    }
    else {
        tmp = *head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

void merge(LIST **first, LIST **second){
    LIST *tmp = *first;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = *second;
    *second = NULL;
    free(*second);
}

LIST *get (LIST **head,int x){
    LIST *tmp = *head;
    for (int i = 1; i <= x; ++i) {
        if(tmp != NULL){
            tmp=tmp->next;
        } else{
            printf("Element doesnt exist\n");
            return NULL;
        }
    }
    return tmp;
}

void show(LIST *head){
    if(head == NULL){
        printf("List is empty\n");
    }
    else {
        while(head != NULL){
            printf("%d " , head->key);
            head = head->next;
        }
        printf("\n");
    }
}

void avgtime (LIST *head, int n){
    #ifdef _WIN32
        SYSTEMTIME timer;
    #else
        struct timeval timer;
    #endif
    int start;
    int end;
    double sum = 0;
    double avg = 0;

    for (int i=1;i<=10000;i++){
        #ifdef _WIN32
            GetSystemTime(&timer);
            start = (timer.wSecond * 1000) + timer.wMilliseconds;
        #else
            gettimeofday(&timer, NULL);
            start = (timer.tv_sec * 1000000) + timer.tv_usec;
        #endif
        
        LIST *x = get(&head,n);

        #ifdef _WIN32
            GetSystemTime(&timer);
            end = (timer.wSecond * 1000) + timer.wMilliseconds;
        #else
            gettimeofday(&timer, NULL);
            end = (timer.tv_sec * 1000000) + timer.tv_usec;
        #endif
        sum = sum + (end - start);
    }
    avg = sum/10000.0;
    #ifdef _WIN32
        printf("Avg time for n = %d : %f (in miliseconds)\n",n,avg);
    #else
        printf("Avg time for n = %d : %f (in microseconds)\n",n,avg);
    #endif
}


int main() {
    LIST *test = NULL;
    LIST *head = NULL;
    LIST *sec = NULL;
    srand(time(NULL));

    for (int i = 1; i <= 1000; i++) {
        add(&test, rand());
    }
    avgtime(test, 1);
    avgtime(test, 250);
    avgtime(test, 500);
    avgtime(test, 750);
    avgtime(test, 1000);
    avgtime(test, (rand() % 1000) + 1);

    show(test);

    add(&head, 4);
    add(&head, 5);
    add(&sec, 6);
    add(&sec, 7);
    merge(&head, &sec);
    show(sec);
    show(head);
}