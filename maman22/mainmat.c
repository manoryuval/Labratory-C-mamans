#include "mymat.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*The program allows users to perform various operations on matrices, including reading values, printing, addition, subtraction, multiplication, scalar 
multiplication, and transposition. It features robust input parsing and 
validation to handle different command formats and potential errors.

Users can input up to a maximum of 100 characters per line.*/
int main(){
    char input[MAX_INPUT];/*Buffer to store raw user input.*/
    char copy_input[MAX_INPUT];/*Copy of the input for validation purposes.*/
    /*Initialize all predefined matrices (MAT_A to MAT_F) to zero. */
    to_zero_mat(MAT_A);
    to_zero_mat(MAT_B);
    to_zero_mat(MAT_C);
    to_zero_mat(MAT_D);
    to_zero_mat(MAT_E);
    to_zero_mat(MAT_F);
    while (1) {
        printf("enter command:\n");
        if (!fgets(input, MAX_INPUT, stdin)){ 
            printf("Error reading input\n");
            break;
        }
        if (strlen(input) == MAX_INPUT - 1 && input[MAX_INPUT - 2] != '\n') {
            printf("Input too long, please enter less than %d characters\n", MAX_INPUT);
            continue;
        }
        strncpy(copy_input, input, sizeof(copy_input) - 1);
        copy_input[sizeof(copy_input) - 1] = '\0';
        input[strcspn(input, "\n")] = '\0';
        mat* mat_arg1 = NULL;
        mat* mat_arg2 = NULL;
        mat* mat_arg3 = NULL;
        char* command = strtok(input, " \n\t");
        if (command == NULL) {
            printf("No command entered\n");
            continue;
        }
        char* arg1 = NULL;
        char* arg2 = NULL;
        char* arg3 = NULL;
        char* arg4 = NULL;
        printf("command: %s\n", command);
        if (get_command_by_name(command) == CMD_READ){
            arg1 = strtok(NULL, " ,");
            arg2 = strtok(NULL, "\0");
            arg3 = strtok(NULL, " ");
            if (arg1) trim_whitespace(arg1);
            /*if (arg2) remove_whitespace(arg2);*/
        }else
        {
            arg1 = strtok(NULL, " ,");
            arg2 = strtok(NULL, " ,");
            arg3 = strtok(NULL, " ,");
            arg4 = strtok(NULL, "");
            if(arg1) trim_whitespace(arg1);
            if(arg2) trim_whitespace(arg2);  
            if(arg3) trim_whitespace(arg3);
            if(arg4) trim_whitespace(arg4);
        }
        printf("arg1: %s\n", arg1);
        printf("arg2: %s\n", arg2);
        printf("arg3: %s\n", arg3);
        printf("arg4: %s\n", arg4);
        

        switch (validator(copy_input, command, arg1, arg2, arg3, arg4)) {
        case ERR_INVALID_MATRIX_NAME:{
            printf("Undefined matrix name\n");
            break;
        }
        case ERR_INVALID_COMMAND_NAME:{
            printf("Undefined command name\n");
            break;
        }
        case ERR_ARG_NOT_NUM:{
            printf("Argument is not a number\n");
            break;
        }
        case ERR_TEXT_AFT_END:{
            printf("Extraneous text after end of command\n");
            break;
        }
        case ERR_MISSING_ARG:{
            printf("Missing argument\n");
            break;
        }
        case ERR_ILEGAL_COMMA:{
            printf("Illegal comma\n");
            break;
        }
        case ERR_MISSING_COMMA:{
            printf("Missing comma\n");
            break;
        }
        case ERR_MULTIPLE_COMMA:{
            printf("Multiple consecutive commas\n");
            break;
        }
        case ERR_ARG_NOT_SCALAR:{
            printf("Argument is not a scalar\n");
            break;
        }
        case VALID:{
            printf("Valid command\n");
            switch (get_command_by_name(command)) {
                case CMD_READ:{
                    if (arg1&&arg2&&!arg3){
                        mat_arg1 = get_matrix_by_name(arg1);
                        read_mat(*mat_arg1, arg2);
                    } 
                    break;
                }
                case CMD_ADD:{
                    if (arg1&&arg2&&arg3&&!arg4){
                        mat_arg1 = get_matrix_by_name(arg1);
                        mat_arg2 = get_matrix_by_name(arg2);
                        mat_arg3 = get_matrix_by_name(arg3);
                        add_mat(*mat_arg1, *mat_arg2, *mat_arg3);
                    }
                    break;
                }
                case CMD_SUB:{
                    if (arg1&&arg2&&arg3&&!arg4){
                        mat_arg1 = get_matrix_by_name(arg1);
                        mat_arg2 = get_matrix_by_name(arg2);
                        mat_arg3 = get_matrix_by_name(arg3);
                        sub_mat(*mat_arg1, *mat_arg2, *mat_arg3);
                    }
                    break;
                }
                case CMD_MUL:{
                    if (arg1&&arg2&&arg3&&!arg4){
                        mat_arg1 = get_matrix_by_name(arg1);
                        mat_arg2 = get_matrix_by_name(arg2);
                        mat_arg3 = get_matrix_by_name(arg3);
                        mul_mat(*mat_arg1, *mat_arg2, *mat_arg3);
                    }
                    break;
                }
                case CMD_MUL_SCALAR:{
                    if (arg1&&arg2&&arg3&&!arg4){
                        mat_arg1 = get_matrix_by_name(arg1);
                        mat_arg3 = get_matrix_by_name(arg3);
                        mul_skalar(*mat_arg1, atof(arg2), *mat_arg3);
                    }
                    break;
                }
                case CMD_TRANS:{
                    if (arg1&&arg2&&!arg3){
                        mat_arg1 = get_matrix_by_name(arg1);
                        mat_arg2 = get_matrix_by_name(arg2);
                        trans_mat(*mat_arg1, *mat_arg2);
                    }
                    break;
                }
                case CMD_STOP:{
                    if (!arg1)
                    {
                        stop();
                    }
                    break;
                }
                case CMD_PRINT:{
                    if (arg1&&!arg2){
                        mat_arg1 = get_matrix_by_name(arg1);
                        print_mat(*mat_arg1);
                    }              
                    break;
                }
                default:{
                    printf("Undefined command name\n");
                    break;
        
                }
            }
            break;
        }
        }
    }  
return 0;
}