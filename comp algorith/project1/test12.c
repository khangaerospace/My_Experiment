#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
struct term{
    char term[200]; // assume terms are not longer than 200
    double weight;
};

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
        printf("Could not open file \n");
        //return 1;
    }
    else{
        fgets(line,sizeof(line), fp);
        int number;
        number = atoi(line);
        struct term *total = malloc(number*sizeof(struct term));
        char all[number];
        int weight1,intnum,weight2,num2=0 ;
        char city[50], more1[50],more2[50], more3[50];
        //fgets(line,sizeof(line), fp);
        for(int i = 1; i < number ;i++){
            
            fgets(line,sizeof(line), fp);
            //printf("%s",line);
            //char weight[50];
            //struct term *newterm = malloc( sizeof(struct term));
            sscanf(line,"%ld %n", &weight1, &intnum);
            //sscanf(line, " %s", pos);
           // printf(" num%s\n ", pos);
            //printf("%ld ",weight1);
            weight2 = weight1;
            int lenofin=0;
            //total->term[i] = city+country;
            while(weight2!=0){
                weight2 = weight2/10;
                lenofin++;
            }
            char *country = line+intnum;
            while (*country && isspace((unsigned char)*country)){
                ++country;
                puts(country);
            }
            //printf("%s", country);
            //printf("%s",country);
            strcpy(city,country);
            
            strcpy(total[num2].term, country);
            total[i-1].weight= weight1;
            num2++;
        }
    qsort(total,number,sizeof(struct term),sorting_Lexicographical);

    /*for(int k = 0;k<10;k++){
        printf("%s",total[k].term);
    }*/
    *terms = total;
    *pnterms = number;
    }
}

int lowest_match(struct term *terms, int nterms, char *substr){
    int left = 0;
    int right = nterms - 1;
    char target[200];
    strcpy(target, substr);
    while(left < right){
        int mid = (left + right) / 2;
        if(strcmp(target, terms[mid].term) < 0){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    char b[200];
    strncpy(b,terms[left].term,strlen(substr));
    /*if (strcmp(target, b) != 0){
        return -1;
    }*/
    return left;
}


int highest_match(struct term *terms, int nterms, char *substr){
    int left = 0;
    int right = nterms - 1;
    char target[200];
    strcpy(target, substr);
    while(left < right){
        int mid = (left + right) / 2;
        if(strcmp(target, terms[mid].term) > 0){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    char b[200];
    strncpy(b,terms[right].term,strlen(substr));

    /*if (strcmp(target, b) != 0){
        return -1;
    }*/
    return right;
}


int main(void)
{
    struct term *terms;
    int nterms ;
    int *pnterms = &nterms;
    read_in_terms(&terms, &nterms, "C:\\Users\\khang\\OneDrive\\Music\\Documents\\school UofT textbook\\year 1 semester 2\\esc190 comp algorith\\project1\\wiktionary2.txt");
    printf("%d\n",highest_match(terms, nterms, "A Estrada"));
    printf("%d",lowest_match(terms, nterms, "A Estrada"));

    //struct term *answer;
    //int n_answer;
    //autocomplete(&answer, &n_answer, terms, int nterms, "Tor");
    //free allocated blocks here -- not required for the project, but good practice
    return 0;
}
