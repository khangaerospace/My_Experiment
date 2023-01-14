#include<stdio.h>
#include <math.h>

struct node{
    int data; 
    struct node *next; 
};

struct mode{
    void *p_data; //a pointer to data (allocated with malloc)
    int type; // 0 if int, 1 if float, 2 if double
    struct node *next;
};

void printdata(struct node *head){
    struct node *cur =head;

    while(cur != NULL){
        printf("%ld ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}


int printdatarecursively(struct node *head){
    struct node *cur =head;
    if(cur != NULL){

        printf("%ld ",cur->data);
        cur = cur->next;
        return printdatarecursively(cur);  
    }
    else{
        printf("Done\n");
       return 0; 
    }
    
}
//void append(struct mode *head, int type, int p_data){
//    if (type = 0){
        //int value = *p_data;
//        append_int(head, type, p_data);
//    }
//    else if (type = 1){
        //float value = *p_data;
//        append_float(head, type, p_data);
//    }
//    else if(type =3 ){
        //double value = *p_data;
//        append_double(head, type, p_data);
///    }
//}
void append_int(struct mode *head, int datatype,int value){
    struct mode *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct mode *mode = (struct mode *)malloc(sizeof(struct mode));
    int *data = (int *)malloc(sizeof(value));
    *data = value;
    //int *dataposition = &value;
    mode->p_data = data;
    mode->type = datatype;
    mode->next = NULL;
    cur->next = mode;
}

void append_float(struct mode *head, int datatype,float value){
    struct mode *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct mode *mode = (struct mode *)malloc(sizeof(struct mode));
    void *data = (int *)malloc(sizeof(float));
    *(float *)data = value;
    //int *dataposition = &value;
    mode->p_data = data;
    mode->type = datatype;
    mode->next = NULL;
    cur->next = mode;
}

void append_double(struct mode *head, int datatype,double value){
    struct mode *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct mode *mode = (struct mode *)malloc(sizeof(struct mode));
    void *data = (int *)malloc(sizeof(double));
    *(double *)data = value;
    //int *dataposition = &value;
    mode->p_data = data;
    mode->type = datatype;
    mode->next = NULL;
    cur->next = mode;
}

void print_int(struct mode*mode){
    printf("%ld ", *(int *)mode->p_data);
}

void print_mode(struct mode *mode){
    while(mode != NULL){
        int v = mode->type;
        if (v == 0){
            printf("%ld ", *(int *)(mode->p_data));
        }
        if (v == 2){
            printf("%f ",*(double *)mode->p_data);  
        }
        if(v == 1){
            printf("%f ",*(float *)mode->p_data);
        }
        mode = mode->next;
    }
}

int search_list(struct node *node, int x){
    
    if(node->data == x){
        printf("%ld",node->data );
        return(node);
    }
    else if(node->next == NULL){
        return NULL;
    }
    else{
        return( search_list(node->next,x));
    }
}

int main(void)
{
    // struct node node0;
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->data = 3;

    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node0->next = node1;
    node1->data = 5;
    node1->next = NULL;

    //printf("hi\n");
    printdata(node0);
    printdatarecursively(node0);
    struct mode *mode = (struct mode *)malloc(sizeof(struct mode));
    int a = 5;
    mode ->p_data = &a;
    mode ->type = 0;
    mode->next = NULL;
    
    search_list(node0, 5);
    append_double(mode,2,4.3);
    append_int(mode, 0, 4);
    append_float(mode,1,6.5464564);
    
    //print_int(mode)
    print_mode(mode);
    //while(mode != NULL){
    //    printf("%f ",*(double *)mode->p_data);
    //    mode = mode->next;
    //}
    
    //printf("%ld \n", *(int *)mode->p_data);
    //printf("%ld", mode->*p_data);
    char str1[] = "This is ";
    printf("%s\n", str1[1]);
    return 0;
}