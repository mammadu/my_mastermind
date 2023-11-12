#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "../include/my_mastermind.h"

typedef struct{
    char flag_secret_code_representation;
    bool flag_secret_code_on;
    int flag_secret_code_position;
    char flag_attempts_representation;
    bool flag_attempts_on;
    int flag_attempts_position;
}flag_struct;

flag_struct init_flag_struct(){
    flag_struct flag;
    flag.flag_secret_code_representation = 'c';
    flag.flag_secret_code_on = false;
    flag.flag_attempts_representation = 't';
    flag.flag_attempts_on = false;
    return flag;
}


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