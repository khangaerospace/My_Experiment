#include <stdio.h>
#include <stdlib.h>

struct student_record{
    int esc180;
    int phy180;
};

//has no effect

void f0(int a){
    a = 100;
}
//no effect
void f(struct student_record s){
    s.esc180 = 100;
}
//has an effect
void f1(int *a){
    *a = 100;
}

//has an effect
void f2(struct student_record *ps){
    (*ps).esc180 = 100; //has an effect
}

// (*a).b is equivalent to a->b
// same af f2
void f3(struct student_record *ps){
    ps->esc180 = 100; //has an effect
}

int *make_arr(int size_arr){
    return (int *)malloc(size_arr * sizeof(int));
}

int *make_arr10_wrong(){
    int a[10]; //local variable
    return a;
}

int *make_int_wrong(){
    int a; //local variable
    return &a;
}

int main(void)
{
    struct student_record s;
    struct student_record s1;
    s.esc180 = 94;
    s1.esc180 = 95;
    f(s);
    f1(&s.esc180); //has an effect
    f2(&s);

    //int a = 5;
    //float b = (float)a;
    

    printf("%ld %ld %ld\n", (long int)(&s), (long int)(&s.esc180), (long int)(&s.phy180));

    int *a = (int *)malloc(10 * sizeof(int)); 
    int size_arr = 10;
    int *b = (int *)malloc(size_arr * sizeof(int)); 
    a[5] = 15;  // *(a + 5) = 15;
    // malloc returns a object of type void*, we then cast it to int *

    int *c = make_arr(50);
    printf("c: %ld", (long int)c);
    int i;
    for(i = 0; i < 50; i++){
        c[i] = 15;
    }
    c[10] = 40; //*(c+10) = 40
    free(c);
    //c[10] = 50;
}