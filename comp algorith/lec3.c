#include<stdio.h>
void f(int a[])
{
    a[0] = 5;//equivalently *a =5
}

void f2(int *a)
{
    a[0] = 5; // equivalent *a = 5
}

int main(void)
{
   int a[3] = {2,3,4}; //3 is th elength of the array
   // a[0] is the same as start *a
   printf("%d\n", a[1] );
   int an_int  = 0;
   double a_double = 0;
   char b = 'a'; // the char desind with a single qoute
   // we can see how much space it take off
   printf("size of a thing %ld byte\n", sizeof(an_int)); 
}