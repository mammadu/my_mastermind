#include <stdlib.h>
#include "../include/my_ngram_functions.h"

int* my_ngram(char* str){
    int* ngram = malloc(sizeof(int) * NGRAM_ARRAY_LENGTH);
    memset(ngram, 0, NGRAM_ARRAY_LENGTH); // initialize ngram array to 0

    for (int i = 0; i < (int)strlen(str); i++) // loop through each character in each argument
    {
        ngram[(int)str[i]]++; // increment the count of the character in the ngram array. The index is the key of the character
    }
    return ngram;
}