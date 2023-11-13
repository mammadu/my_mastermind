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

    int secret_code_array[SECRET_CODE_LENGTH];
    create_secret_code(secret_code_array);

    for (int i = 0; i < SECRET_CODE_LENGTH; i++)
    {
        printf("%d", secret_code_array[i]);
    }
    printf("\n");
}
