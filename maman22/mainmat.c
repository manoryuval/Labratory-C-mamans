#include "mymat.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    char input[MAX_INPUT];
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
        mat* mat_arg1 = NULL;
        mat* mat_arg2 = NULL;
        mat* mat_arg3 = NULL;
        char* command = strtok(input, " \n");
        char* arg1 = strtok(NULL, ",");
        char* arg2 = strtok(NULL, ",");
        char* arg3 = strtok(NULL, ",");
        char* arg4 = strtok(NULL, ",");
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
    }  
return 0;
}