#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "../include/my_mastermind_functions.h"

int main (int argc, char *argv[]){
    char *secret_code =argv[1];
    bool is_valid = is_user_secret_code_valid(secret_code);
    printf("is user secret code valid: %s\n", boolean[is_valid]);
}