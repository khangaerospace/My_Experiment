#include <stdio.h>
#include <stdlib.h>


double my_atof(char *str){
    double number;
    char integer;
    int i =0;
    
    while( str[i] != '.'){
            (integer = str[i]);
            number = number*10 + (integer - '0');
            i++;   
    }
    i = i+1;
    double number2;
    int n=1;
    while(str[i] != '\0'){
        integer = str[i];
        number2 = (number2*(10) + (integer - '0'));
        
        n++;
    }
    number2 = 1/number2;
    number = number + number2;
    return number;
}

