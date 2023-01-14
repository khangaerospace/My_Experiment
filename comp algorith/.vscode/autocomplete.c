#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "autocomplete.h"


int sorting_Lexicographical( const void *a, const void *b)
{
    struct term *ia = (struct term *)a;
    struct term *ib = (struct term *)b;
    return strcmp(ia->term, ib->term);

}

void read_in_terms(struct term **terms, int *pnterms, char *filename){
    char line[200];
    int num = 0;
    char line1;
    struct term *temp = (struct term *) malloc(sizeof(struct term));

    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
//        printf("Could not open file \n");
        return;
    }
    else{
        fgets(line,sizeof(line), fp);
        int number;
        number = atoi(line);
        struct term *total = malloc(number*sizeof(struct term));
        char all[number];
        int weight1,intnum,weight2,num2=0 ;
        char city[50], more1[50],more2[50], more3[50];
        for(int i = 0; i < number ;i++){

            fgets(line,sizeof(line), fp);
            sscanf(line,"%lf %n", &weight1, &intnum);
            weight2 = weight1;
            int lenofin=0;
            while(weight2!=0){
                weight2 = weight2/10;
                lenofin++;
            }
            char *country = line+intnum;
            while (*country && isspace((unsigned char)*country)){
                ++country;
//                puts(country);
            }

            country[strlen(country)-1] = 0;
            strcpy(city,country);

            strcpy(total[num2].term, country);
            total[i-1].weight= weight1;
            num2++;
        }
//        for(int k = 0;k<number;k++){
//            printf("%s\n",total[k].term);
//            printf("%1.0f\n",total[k].weight);
//        }

        qsort(total,number,sizeof(struct term),sorting_Lexicographical);

//        for(int k = 0;k<number;k++){
//            printf("%s\n",total[k].term);
//            printf("%1.0f\n",total[k].weight);
//        }
        *terms = total;
        *pnterms = number;
    }
}


int lowest_match(struct term *terms, int nterms, char *substr){
    int left = 0;
    int right = nterms - 1;
    while(right - left >= 1){
        int mid = (left + right) / 2;
        if(strncmp(substr, terms[mid].term, strlen(substr)) <= 0){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    char b[200];
    memset(b,'\0',200);
    strncpy(b,terms[left].term,strlen(substr));
    if (strcmp(substr, b) != 0){
        return -1;
    }
    return left;
}


int highest_match(struct term *terms, int nterms, char *substr){
    int left = 0;
    int right = nterms - 1;
    while(left < right){
        int mid = (left + right) / 2 + 1;
        if(strncmp(substr, terms[mid].term, strlen(substr)) >= 0){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    char b[200];
    memset(b,'\0',200);
    strncpy(b,terms[right].term,strlen(substr));
    if (strcmp(substr, b) != 0){
        return -1;
    }
    return right;
}


int sorting_weight( const void *a, const void *b)
{
    struct term *ia = (struct term *)a;
    struct term *ib = (struct term *)b;
    int numa = ia->weight;
    int numb = ib->weight;
    return (numb - numa);

}


void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr){
    struct term *totalans = malloc(nterms*sizeof(struct term));
    int lownum = lowest_match(terms, nterms, substr);
    int highnum = highest_match(terms, nterms, substr);
    if(highnum == lownum){
        *answer = terms[highnum].term;
        n_answer = 1;
    }
    else
    {
        for(int i =0; i < highnum-lownum; i++){
            //totalans[i] = terms[lownum+i];
            strcpy(totalans[i].term, terms[lownum+i].term);
            totalans[i].weight= terms[lownum+i].weight;


        }
        long int totalanswer = highnum-lownum;
        qsort(totalans, totalanswer,sizeof(struct term),sorting_weight);
        *answer = totalans;
        *n_answer = totalanswer;
    }


}