#include "../include/my_mastermind_functions.h"

int main (int argc, char *argv[]){
    flag_struct flags = init_flag_struct();
    check_for_flags(argc, argv, &flags);
    // if we find a flag we must ensure the next argument is valid
    // validate argument by making sure it's an integer
    // if valid
        // set the code
        // set the max number of attempts

    char* welcome_message = "Please enter a valid guess\n";
    printf("%s", welcome_message);

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
    // user_guess[SECRET_CODE_LENGTH] = '\0';
    while (attempt_count < max_attempts){
        printf("---\nRound %d of %d\n", attempt_count + 1, max_attempts);
        // char* prompt = ">";
        // printf("%s", prompt);
        // fflush(stdout); //for some reason the prompt doesn't show up without this
        int character_read_count = 0;
        int index = 0;
        char buffer;
        int read_val = read(0, &buffer, 1);
        // printf("buffer = %c\n", buffer); //debug
        while (buffer != '\n' && read_val != 0){
            index = character_read_count % SECRET_CODE_LENGTH;
            // printf("index = %d\n", index); //debug
            user_guess[index] = buffer;
            character_read_count++;
            read_val = read(0, &buffer, 1);
            // printf("read_val = %d\n", read_val); //debug
            // printf("buffer = %c\n", buffer); //debug
            if (read_val == 0){ //read_val ==) means EOF (ctrl + d)
                printf("EOF\n");
                exit(0);
            }
        }
        if (!is_str_a_number(user_guess)){
            printf("Wrong input!\n");
            continue;
        }
        else if (is_user_guess_correct(user_guess, secret_code_array)){
            printf("Congratz! You did it!\n");
            return 0;
        }
        else{
            evaluate_user_guess(user_guess, secret_code_array);
        }
        attempt_count++;
    }
}
