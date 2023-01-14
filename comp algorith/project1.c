#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
struct term{
    char term[200]; // assume terms are not longer than 200
    double weight;
};

/*void read_in_terms(struct term **terms, int *pnterms, char *filename){
    char line[200];
    char sentence[999999];
    int num = 0;
    char line1;
    struct term *ter;
    int i;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file \n");
        //return 1;
    }
    else{
        while(fp !=NULL){
            i++;
            fgets(line,sizeof(line), fp);
            //puts(line);
            sentence[num] = line; 
            printf("%s\n",sentence[num]);
            if(sentence[num] == sentence[num-1]){
                break;
            }
            printf("%s\n",line);

            /*char c;
            for (i = 0; i < strlen(line); i++){
                c = line[i];
                if(c==';'){
                    size_t s = strlen(line + i + 1);
                    memmove(line + i, line + i + 1, s+1);
                    --i;
                }

            }
            int *ter2 = malloc(sizeof(line));
            *ter2 = &line;
            (*terms)[num]=*ter;

            strcpy(ter->term, *ter2);
            
            
            free(ter2); 
            num++;
        }
        *pnterms=num;  
 
    }

    
    
    //ter//->term = line;
}*/

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
        for(int i = 0; i <93828 ;i++){

            fgets(line,sizeof(line), fp);
            printf("%s",line);
            
            void *ter2 = (int *)malloc(sizeof(line));
            *(char *)ter2 = line;
            temp->term[num] = ter2;
            num++;
            temp = (struct term *) realloc(temp, (1+num)*(sizeof(struct term)));
        }
    *pnterms=num;
    *terms = temp;
    
    }
}

int main(void)
{
    struct term *terms;
    int nterms ;
    int *pnterms = &nterms;
    read_in_terms(&terms, &nterms, "C:\\Users\\khang\\OneDrive\\Music\\Documents\\school UofT textbook\\year 1 semester 2\\esc190 comp algorith\\project1\\cities.txt");
    //lowest_match(terms, nterms, "Tor");
    //highest_match(terms, nterms, "Tor");
    for(int i = 0; i <200 ;i++){
        printf("terms %ld\n", terms->term[i]);
    }
    char line[200];
    //char filename = "C:\\cities.txt";
    //FILE *fp = fopen("C:\\Users\\khang\\OneDrive\\Music\\Documents\\school UofT textbook\\year 1 semester 2\\esc190 comp algorith\\project1\\cities.txt", "r");
    
    struct term *answer;
    int n_answer;
    //autocomplete(&answer, &n_answer, terms, int nterms, "Tor");
    //free allocated blocks here -- not required for the project, but good practice
    return 0;
}