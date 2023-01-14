#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "fuctionprot.h"


//struct node{
#include "workprot.c"
//////    int value;
//    struct node *next;
//};

int main(void)
{
    int num = 6;
    printfun();
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->data = 3;

    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node0->next = node1;
    node1->data = 5;

    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node1->next = node2;
    node2->data = 8;
    //node2->next = NULL;

    printf("hello\n");

    return 0;
}
