#include<stdio.h>
#include <math.h>
void change(int *p_a)
{
    *p_a = 10;
}


void Sorting(int arr[], int n) 
{   
    
    int l = 0;
    int c;
    for( int i = 1; i < n; i++)
    {
        
        int key = arr[i];
        c = i - 1;
        while(arr[c] > key && c >= 0)
        {
            arr[c+1]= arr[c];
            c = c -1;
        }
        arr[c+1] = key;
    
    }

    int j = 0;
     while( j < n )
    {
        printf("%ld ", arr[j]);
        j++;
    }
    printf("\n");
    return 0;
}



int main(void)
{
    int a = 5;
    printf("%ld\n",a);
    int *p_a = &a;
    change(p_a);
    printf("%ld\n", a);

    
    int arr[]= {8,2,6,3,4,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    Sorting(arr,n);
    
    return 0;
}