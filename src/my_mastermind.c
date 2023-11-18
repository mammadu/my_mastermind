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

    // set secret code
    char secret_code_array[SECRET_CODE_LENGTH + 1]; // +1 for null terminator
    if (flags.flag_secret_code_on && is_user_secret_code_valid(argv[flags.flag_secret_code_position])){
        // set the secret code to the user's secret code
        strcpy(secret_code_array, argv[flags.flag_secret_code_position]);
    }
    else{
        // create a random secret code
        create_random_secret_code(secret_code_array);
    }

    //set max number of attempts
    int max_attempts;
    if (flags.flag_attempts_on && is_user_attempt_count_valid(argv[flags.flag_attempts_position])){
        max_attempts = atoi(argv[flags.flag_attempts_position]);
    }
    else{
        max_attempts = MAX_ATTEMPTS;
    }

    int attempt_count = 0;
    char user_guess[SECRET_CODE_LENGTH + 1];
    while (attempt_count < max_attempts){
        printf("---\nRound %d of %d\n", attempt_count + 1, max_attempts);
        /*
        User will enter a number
        We will check if the number is valid i.e. only has 4 digits
            if the number is valid
                we will check if the number is correct
                    if the number is correct
                        we will print a message and exit
                    else
                        we count the number of well placed pieces and misplaced pieces
                        we then print those values
            else
                we will print a message saying it's an invalid number
        */
        int characters_read = 0;
        char buffer;
        char* prompt = ">";
        printf("%s", prompt);
        read(0, &buffer, 1);
        while (buffer != '\n'){
            if (characters_read >= SECRET_CODE_LENGTH){
                printf("You entered too many characters\n");
                characters_read = 0;
                read(0, &buffer, 1);
                printf("%s", prompt);
            }
            if (!is_char_a_number(buffer)){
                printf("You entered an invalid character\n");
                characters_read = 0;
                read(0, &buffer, 1);
                printf("%s", prompt);
            }
            user_guess[characters_read] = buffer;
            characters_read++;
            read(0, &buffer, 1);
        }
        printf("evaluate guess %s\n", user_guess); //debug/placeholder
        attempt_count++;
    }
}
