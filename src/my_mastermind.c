#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/my_mastermind.h"

int main (){
    int secret_code_array[SECRET_CODE_LENGTH];
    create_secret_code(secret_code_array);

    for (int i = 0; i < SECRET_CODE_LENGTH; i++)
    {
        printf("%d\n", secret_code_array[i]);
    }
}

void create_secret_code(int *secret_code){
    // Seed the random number generator with the current time
    srand(time(NULL));

    for (int i = 0; i < 4; i++)
    {
        secret_code[i] = rand() % 9;
    }
}