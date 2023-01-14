#include <stdio.h>
#include <stdlib.h>

int my_strncmp (char *str1, char *str2, int num ){
    char *s1 =str1;
    char *s2 = str2;
    if(num == 0){
        return 0;
    }
    else if(s1 < s2){
        return -1;
    }
    else if(s1>s2){
        return 1;
    }
    else if(s1 == NULL || '\0'){
        return 0;
    }
    num = num -1;
    my_strncmp(s1,s2,num);
}

void main(){
    printf("%d\n", my_strncmp("ESC180", "ESC190", 3)); // returns 0
    printf("%d", my_strncmp("ESC180", "ESC190", 5)); // returns a negative number    
}
