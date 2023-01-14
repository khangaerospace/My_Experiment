#include <stdio.h>
#include <stdlib.h>

void swap(int *p_a, int *p_b)
{
    int temp =*p_a;
    *p_a = *p_b;
    *p_b = temp;

}

int main(void)
{

    int a =5 ;
    int *p_a = &a;
    printf("address of a: %ld\n", p_a);
    *p_a = 4; //a become 4
    int b = 6;
    int *p_b = &b;
    swap(&a , &b);
    swap(&b , &a);
    return 0;
}
