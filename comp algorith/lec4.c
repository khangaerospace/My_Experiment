#include<stdio.h>
#include <math.h>
struct student_record
{
    int esc180;
    int phy180;
}

// has no effect;
;
void f(struct student_record s)
{

    s.esc180 = 100;
}

void f1(int *a)
{
    *a = 100;
}

void f2(struct student_record  *ps){
    (*ps).esc180 = 100; // has an effect
}

//(*a).b is the equivalent to a -> b

// the same as f2
void f3(struct student_record *ps){
    ps->esc180 =100;
}
int main(void){
    struct student_record s;
    struct student_record s1;
    s.esc180 = 90;
    s1.esc180 = 95;
    f(s);
    f1(&s.esc180); // has an effect
    f2(*s.esc180);
    pritnf("%ld %ld %ld ", &s , &s.esc180, &s.phy180);

}