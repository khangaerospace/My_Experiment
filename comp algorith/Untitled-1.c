#include<stdio.h>
#include <math.h>

void print_arr(int *arr, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {

        printf("%ld ", arr[i]);
    }

}


int main(void){
    int a[3] = {4,5,6};
    print_arr(a, 3);
}

// binary notation
// 1011 =1 * 2^3 + 0*2^2+ 1*2^1+1*2^1