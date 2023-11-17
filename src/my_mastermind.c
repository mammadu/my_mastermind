#include "../include/my_mastermind_functions.h"

int main (int argc, char *argv[]){
    flag_struct flags = init_flag_struct();
    check_for_flags(argc, argv, &flags);
    // if we find a flag we must ensure the next argument is valid
    // validate argument by making sure it's an integer
    // if valid
        // set the code
        // set the max number of attempts

    char* prompt = "Will you find the secret code?\nPlease enter a valid guess";
    printf("%s\n", prompt);

    char secret_code_array[SECRET_CODE_LENGTH + 1]; // +1 for null terminator
    if (flags.flag_secret_code_on && is_user_secret_code_valid(argv[flags.flag_secret_code_position])){
        // set the secret code to the user's secret code
        strcpy(secret_code_array, argv[flags.flag_secret_code_position]);
    }
    else{
        // create a random secret code
        create_random_secret_code(secret_code_array);
    }

    printf("the secret code is %s\n", secret_code_array); //debug

}
