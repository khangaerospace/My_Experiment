#include<stdio.h>
#include <math.h>

//append
//length
//max
//rec_length
//rec_maz
//delete
struct note{
    int data; // in python: void *data, and also the data type
    struct note *next;// NULL if the current node is the last one


};

void append(struct node *head, int value){
    struct node *cur = head;
    while(cur-> != NULL){
        cur = cur ->next;
    }
    //cur->next is now equal to NULL
    struct note *note = (struct node *)malloc(sizeof(struct note));
    node->data =value;
    node->next=NULL;
    cur->next =node;
}

int max_list(struct node *head){
    struct node *cur = head;
    int curmax = cur->value;
    while(cur != NULL){
        if(cur->data > curmax){
            curmax = cur->data;
        }
        cur = cur->next;
    }
    return curmax;
}
int main(void)
{
    // struct node node0;
    struct note *note0 = (struct node *)malloc(sizeof(struct note));
    note0 ->data=3;

    struct note *note1 = (struct node *)malloc(sizeof(struct note));
    note0 ->data=note1;
    note1->data = 5;
    note1->next=NULL;
    printf("hi\n");
    return 0;
}