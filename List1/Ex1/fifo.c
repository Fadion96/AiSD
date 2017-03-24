#include <stdlib.h>
#include <stdio.h>

typedef struct FIFO{
    struct FIFO *next;
    int key;
}FIFO;

void push (FIFO **head, FIFO **tail, int key){
    FIFO *new;
    FIFO *tmp;
    new = (FIFO *)malloc(sizeof(struct FIFO));
    new->key = key;
    new->next = NULL;

    if(*head == NULL){
        *head=new;
        *tail=new;
    }
    else {
        tmp = *tail;
        tmp->next=new;
        *tail=new;
    }
}

void pop(FIFO **head,FIFO **tail){
    FIFO *tmp = *head;
    if(*head == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("Delete: %d \n" , tmp->key);
        tmp=tmp->next;
        if(*head==*tail){
            *tail=NULL;
        }
        *head=NULL;
        *head=tmp;
    }
}
void show(FIFO *head){
    if(head == NULL){
        printf("Queue is empty\n");
    }
    else {
        while(head != NULL){
            printf("%d " , head->key);
            head = head->next;
        }
        printf("\n");
    }
}

int main(){
    FIFO *head = NULL;
    FIFO *tail = NULL;

    show(head);
    push(&head,&tail,4);
    push(&head,&tail,6);
    show(head);
    pop(&head,&tail);
    show(head);
    pop(&head,&tail);
    show(head);
    pop(&head,&tail);
    push(&head,&tail,7);
    show(head);
}