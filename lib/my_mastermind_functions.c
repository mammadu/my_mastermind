#include "../include/my_mastermind_functions.h"

flag_struct init_flag_struct(){
    flag_struct flag;
    flag.flag_secret_code_representation = 'c';
    flag.flag_secret_code_on = false;
    flag.flag_attempts_representation = 't';
    flag.flag_attempts_on = false;
    return flag;
}

bool is_user_secret_code_valid(char *user_secret_code){
    // check if the user's secret code is valid
    // if it is return true
    // else return false
    if (user_secret_code == NULL){
        printf("You must supply a valid secret code with flag 'c'\n");
        return false;
    }
    int secret_code_length = strlen(user_secret_code);
    if (secret_code_length != SECRET_CODE_LENGTH){
        printf("The secret code must be %d digits long\n", SECRET_CODE_LENGTH);
        return false;
    }
    if (!is_str_a_number(user_secret_code)){
        printf("The secret code must be a number\n");
        return false;
    }
    else{
        return true;
    }
}

bool is_user_attempt_count_valid(char *user_attempt_count){
    if (user_attempt_count == NULL){
        printf("You must provide a valid attempt count with flag 't'\n");
        return false;
    }
    if (!is_str_a_number(user_attempt_count)){
        printf("The number of attempts must be a number\n");
        return false;
    }

    if (strlen(user_attempt_count) > SECRET_CODE_LENGTH){
        printf("The number of attempts must be less than %d digits\n", SECRET_CODE_LENGTH);
        return false;
    }
    else{
        return true;
    }
}

bool is_str_a_number(char *str){
    // check if the string is a number
    // if it is, return true
    // else return false
    int str_length = strlen(str);
    for (int i = 0; i < str_length; i++)
    {
        if (!is_char_a_number(str[i])){
            return false;
        }
    }
    return true;
}

bool is_char_a_number(char character){
    // check if the character is a number
    // if it is, return true
    // else return false
    if (character < '0' || character > '9'){
        return false;
    }
    else{
        return true;
    }
}

void check_for_flags(int argc, char *argv[], flag_struct *flags){
    for (int i = 1; i < argc; i++){
        if (argv[i][0] == '-'){
            if (argv[i][1] == flags->flag_secret_code_representation && strlen(argv[i]) == 2){
                flags->flag_secret_code_on = true;
                flags->flag_secret_code_position = i + 1;
            }
            else if (argv[i][1] == flags->flag_attempts_representation && strlen(argv[i]) == 2){
                flags->flag_attempts_on = true;
                flags->flag_attempts_position = i +1;
            }
            else{
                printf("Invalid flag: %s\n", argv[i]);
            }
        }
    }
}


void create_random_secret_code(char *secret_code_array){
    srand(time(NULL));
    for (int i = 0; i < SECRET_CODE_LENGTH; i++)
    {
        secret_code_array[i] = (rand() % 9) + '0';
    }
    secret_code_array[SECRET_CODE_LENGTH] = '\0';
}
