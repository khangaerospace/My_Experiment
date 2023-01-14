
#include <stdio.h>

#include <stdint.h>
#include <stdlib.h>
#include<string.h>
#include "Q2.h"

int repeats(char **strs, int strs_sz){
    //char *array[strs_sz] = strs;
    for(int i = 0; i <strs_sz; i++){
        for(int c = i+1; c < strs_sz; c++ ){
            if(strs[i] == strs[c]){
                //printf("%d",1);
                return 1;
            }
        }

    }
    //printf("%d",0);
    return 0;
}


// this is not O(n) since I can not think of a way to make this O(n) I am so sorry! But this is O(n^2) 

