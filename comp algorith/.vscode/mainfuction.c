
#include "autocomplete.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


int main(void)
{
    struct term *terms;
    int nterms ;
    int *pnterms = &nterms;
    read_in_terms(&terms, &nterms, "C:\\Users\\khang\\OneDrive\\Music\\Documents\\school UofT textbook\\year 1 semester 2\\esc190 comp algorith\\project1\\cities.txt");
    printf("\n%d\n",lowest_match(terms, nterms, "b"));
    printf("%d\n",highest_match(terms, nterms, "b"));
    struct term *answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, "Tor");
    //free allocated blocks here -- not required for the project, but good practice
    return 0;
}