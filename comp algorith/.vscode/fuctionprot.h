#ifndef FUCTIONPROT_H_INCLUDED
#define FUCTIONPROT_H_INCLUDED

//int f(void);
struct node{
    int data;
    struct node *next;
};
void insert(struct node *prev_node, int value);
void printfun();
void deleatenode(struct node *head, int value);
void freelist(struct node *head);



#endif // FUCTIONPROT_H_INCLUDED