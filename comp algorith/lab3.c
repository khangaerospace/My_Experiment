#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
    int data; 
    struct node *next; 
};

char *my_strcat(char *dest, char *src){
    int len = strlen(dest) ;
    int i;
    for(i = 0; i < strlen(src); i++){
        dest[len +i] = src[i];
        
    }
    dest[len+i]= NULL;
    printf("%s\n", dest);
    
    return dest;
}

int my_strcmp_rec(char *str1, char *str2){
    //printf("%ld and %ld\n", strlen(str1),strlen(str1));
    
    if(*str1 =='\0' && *str2 == '\0'){
        return 0;
    }
    else if(*str1 == *str2){
        printf("%s  and %s\n", str1+1,str2+1);
        return my_strcmp_rec(str1+1,str2+1);
    }
    else{
        return *str1 - *str2;
    }
    
}

int my_true_strcmp(char *str1, char *str2)
{
    if(*str1 =='\0' && *str2 == '\0'){
        return 0;
    }
    else if(*str1 > *str2){
        return 1;
    }
    else if((*str1 < *str2)){
        return -1;
    }
    else{
        return my_true_strcmp(str1+1,str2+1);
    }
}

int my_atoi(char *str){
    //printf("%d a sd\n",isdigit(str));
    if (isdigit(str) == 1){
        //printf("%d",str-'0');
        int c;
        return str-'0';
    }
    else{
        printf("not an integer ");
        return NULL;
    }
}

int cycle_detect(struct node *head){
    struct node *tortoise = head;
    struct node *hare = head;
    while (tortoise != NULL && hare->next !=NULL){
        tortoise = tortoise ->next;
        hare = hare->next->next;
        if (tortoise == hare){
            return 1;
            
        }
    }
    return 0;
}

int main(void)
{
    char str1[10] = "This is ";
    char str2[] = "my name";
    //printf("%ld\n",strlen(str2));    
    my_strcat(str1,str2);

    char str3[] = "zfsd ";
    char str4[] = "asd " ;
    printf("%ld\n", my_strcmp_rec(str3,str4));
    printf("%d \n", my_atoi('9'));
    printf("%d \n", my_atoi('+'));

    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->data = 3;

    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node0->next = node1;
    node1->data = 5;

    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    node1->next = node2;
    node2->data = 8;
    //node2->next = NULL;

    struct node *node3 = (struct node *)malloc(sizeof(struct node));
    node2->next = node1;
    node2->data = 9;
    
    
    printf("%d", cycle_detect(node0));

    //printf("%ld\n", strcmp(str3,str4));
    //printf("%ld\n",strlen(str2));
    //printf("%s\n");
    //my_strcmp_rec(str3,str4);
    return 0;
}
