#include<stdio.h>
#include <math.h>

struct node{
    void *p_data; //a pointer to data
    int type; // 0 if int, 1 if float, 2 if double
    struct node *next;
};

void append_int(struct node *head, int datatype,int value){
    // just append integer
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *mode = (struct node *)malloc(sizeof(struct node));
    int *data = (int *)malloc(sizeof(value));
    *data = value;
    int *dataposition = &value;
    mode->p_data = data;
    mode->type = datatype;
    mode->next = NULL;
    cur->next = mode;
}

void append_float(struct node *head, int datatype,float value){\
    // just append float
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *mode = (struct node *)malloc(sizeof(struct node));
    void *data = (int *)malloc(sizeof(float));
    *(float *)data = value;
    //int *dataposition = &value;
    mode->p_data = data;
    
    mode->type = datatype;
    mode->next = NULL;
    cur->next = mode;
}

void append_double(struct node *head, int datatype,double value){
    // just append float
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *mode = (struct node *)malloc(sizeof(struct node));
    void *data = (int *)malloc(sizeof(double));
    *(double *)data = value;
    //int *dataposition = &value;
    mode->p_data = data;
    
    mode->type = datatype;
    mode->next = NULL;
    cur->next = mode;
}

void print_mode(struct node *mode){
    while(mode != NULL){
        int v = mode->type;
        if (v == 0){
            printf("%d ", *(int *)mode->p_data);
        }
        if (v == 1){
            printf("%f ",*(double *)mode->p_data);  
        }
        if(v == 2){
            printf("%f ",*(float *)mode->p_data);
        }
        mode = mode->next;
    }
    printf("\n");
}


int main(void)
{
    struct node *mode = (struct node *)malloc(sizeof(struct node));
    int a = 5;
    mode ->p_data = &a;
    mode ->type = 0;
    mode->next = NULL;
    append_int(mode, 0, 2);
    append_double(mode,1,4.3);
    append_float(mode,2,6.5);
    print_mode(mode);// Can't print integer but float and double are good
    // can print double but not double or float.
    while(mode != NULL){
        int v = mode->type;
        if (v == 0){
            printf("%ld ", *(int *)mode->p_data);
        }
        if (v == 1){
            printf("%f ",*(double *)mode->p_data);  
        }
        if(v == 2){
            printf("%f ",*(float *)mode->p_data);
        }
        mode = mode->next;
    }
    return 0;
}