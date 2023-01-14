
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "functionprot.h"


int main(void){
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->data = 3;
    int num = 6;
    printfun(num);
    //printf("hello\n");
    return 0;
}
