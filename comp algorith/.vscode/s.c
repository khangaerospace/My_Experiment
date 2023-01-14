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
    char sentence[93828];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file \n");
        //return 1;
    }
    else{
        for(int i = 0; i <93828 ;i++){
            //char so[200];
            fgets(line,sizeof(line), fp);
            printf("%s",line);
            //so = line;
            for(int j = i+1; j<5; j++){
                if
                sentence[i] = line;
            }


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
int lowest_match(struct term *terms, int nterms, char *substr) {
    int left = 0;
    int right = nterms - 1;
    char target[200];
    strcpy(target, substr);
    while(left < right){
        int mid = (left + right) / 2;
        char a[200];
        int len = strlen(substr);
        if(target <= strncpy(a,terms[mid].term,len)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    char b[200];
    strncpy(b,terms[left].term,strlen(substr));
    if (b != target){
        return -1;
    }

    return left;
}




int main(void)
{
    struct term *terms;
    int nterms ;
    int *pnterms = &nterms;
    read_in_terms(&terms, &nterms, "C:\\Users\\khang\\OneDrive\\Music\\Documents\\school UofT textbook\\year 1 semester 2\\esc190 comp algorith\\project1\\cities.txt");
    printf(" return %ld",lowest_match(terms, nterms, "Shan"));


    struct term *answer;
    int n_answer;
    //autocomplete(&answer, &n_answer, terms, int nterms, "Tor");
    //free allocated blocks here -- not required for the project, but good practice
    return 0;
}
