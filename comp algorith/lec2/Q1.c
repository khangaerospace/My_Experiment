#include <stdio.h>

#include <stdint.h>
#include <stdlib.h>
#include<string.h>
#include "Q1.h"

char* concat_all(char **strs, int strs_sz0){
    char *concatenated;

    //printf("%s",strs_sz);
    
    //concatenate all strs_sz strings in strs, and return the resultant string
    //int size = atoi(strs_sz);
    strcpy(concatenated,strs[0]);
    for(int i = 1; i<strs_sz0; i++){
        /*char word;
        prints("%s",strs[i]);
        strcpy(word,strs[i]);*/
        strcat(concatenated,strs[i]);

    }
    //printf("%s", concatenated);
    return concatenated;
}





