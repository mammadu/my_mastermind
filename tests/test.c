#include "../include/my_ngram_functions.h"

int main (int argc, char *argv[]){
    for (int i = 1; i < argc; i++)
    {
        int* ngram = my_ngram(argv[i]);
        printf("ngram for %s:\n", argv[i]);
        for (int j = 0; j < NGRAM_ARRAY_LENGTH; j++)
        {
            if (ngram[j] > 0){
                printf("%c: %d\n", (char)j, ngram[j]);
            }
        }
    }
}