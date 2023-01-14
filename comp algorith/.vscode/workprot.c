#include "fuctionprot.h"



void printfun(){
   printf("say hi\n");
}

void insert(struct node *prev_node, int value){
    if (prev_node == NULL){
        printf("Cannot insert here");
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = prev_node->next;  
  
    
    prev_node->next = new_node;
}

void deleatenode(struct node *head, int value){
    struct node *cur = head;
    struct node *pre_cur;
    while(cur->data != value){
        pre_cur = cur;
        cur = cur->next;
    }
    pre_cur = cur->next;
    free(cur);

    
}

void freelist(struct node *head){
    struct node *temp;

    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }

}


