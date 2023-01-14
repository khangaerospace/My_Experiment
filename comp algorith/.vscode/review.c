#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


int main(void){
    struct node *firstnode = (struct node *)malloc(sizeof(struct node));
    firstnode->data = 1;
    struct node *secondtnode = (struct node *)malloc(sizeof(struct node));
    secondtnode->data = 2;
    firstnode->next = secondtnode;
    secondtnode->next = NULL;
    


}