#include <stdio.h>
#include <stdlib.h>
#include "intset.h"

struct intset{
    struct node *head;
};

struct node{
    int data;
    struct node *next;
};


void intset_create(struct intset **s){
    struct intset *intset = (struct intset *)malloc(sizeof(struct intset));
    struct node *node = (struct node *)malloc(sizeof(struct node));
    intset->head = node;
    *s = intset;
}

void intset_add(struct intset *s, int *elems, int num_elems){
    
    struct intset *total = malloc(num_elems*sizeof(struct node));
    
    for(int i; i< num_elems; i++){
        struct node *nextnode = (struct node *)malloc(sizeof(struct node));
        struct intset *newdata = malloc(sizeof(struct node));
        newdata->head->data = elems[i];
        newdata->head->next = nextnode;
        total[i] = newdata;
    }
    struct intset *last = malloc(sizeof(struct node));
    
    newdata->head->next = NULL;
    total[i] = last;
    s = total;

}

int intset_iselem(struct intset *s, int elem){
    int i =0;
    while (s[i]->head->next != NULL)
    {
        if(s[i]->head->data == elem){
            return 1;
        }
    }
    return 0;
    
}

void intset_remove(struct intset *s, int elem){
    int i = 0;
    while (s[i]->head->next != NULL)
    {
        if(s[i]->head->data == elem){
            free(s[i]->head->next);
            s[i]->head->next = s[i]->head->next->next;
            
        }
    }
}

void intset_union(struct intset *s1, struct intset *s2, struct intset **s3){
    int i = 0;
    while (s1[i]->head->next != NULL)
    {
        if(s1[i]->head->data == s1[i]->head->data){
            s3 = s1[i];
        }
    }

}