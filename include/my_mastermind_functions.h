#ifndef my_mastermind_functions_H  // Include guards to prevent multiple inclusion
#define my_mastermind_functions_H

// Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// define constants
#define SECRET_CODE_LENGTH 4
#define MAX_ATTEMPTS 10

// Define structs
typedef struct{
    char flag_secret_code_representation;
    bool flag_secret_code_on;
    int flag_secret_code_position;
    char flag_attempts_representation;
    bool flag_attempts_on;
    int flag_attempts_position;
}flag_struct;

// Function declaration
void create_secret_code(int *secret_code);
void check_for_flags(int argc, char *argv[], flag_struct *flags);
flag_struct init_flag_struct();
bool is_user_secret_code_valid(char *user_secret_code);
bool is_str_a_number(char *str);

// Variable declaration


#endif  // End of include guards