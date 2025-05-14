#include <string.h>
#include "parser.h"
#include <ctype.h>

CommandType get_command_by_name(char* name) {
    if (strcmp(name, "add_mat") == 0) return CMD_ADD;
    if (strcmp(name, "sub_mat") == 0) return CMD_SUB;
    if (strcmp(name, "mul_mat") == 0) return CMD_MUL;
    if (strcmp(name, "mul_scalar") == 0) return CMD_MUL_SCALAR;
    if (strcmp(name, "trans_mat") == 0) return CMD_TRANS;
    if (strcmp(name, "read_mat") == 0) return CMD_READ;
    if (strcmp(name, "print_mat") == 0) return CMD_PRINT;
    if (strcmp(name, "stop") == 0) return CMD_STOP;
    return CMD_INVALID;
}

void trim_whitespace(char *str) {
    char *start = str;
    char *end;
    int len;

    while (isspace((unsigned char)*start)) {
        start++;
    }

    if (*start == '\0') {
        str[0] = '\0';
        return;
    }

    end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }

    len = end - start + 1;

    memmove(str, start, len);
    str[len] = '\0';
}

void remove_whitespace(char* str) {
    char* p = str;
    char* q = str;

    while (*p) {
        if (!isspace((unsigned char)*p)) {
            *q++ = *p;
        }
        p++;
    }
    *q = '\0';
}


ValidationInput validator(char* input ,char* command, char* arg1, char* arg2, char* arg3, char* arg4) {
    if (get_command_by_name(command) == CMD_INVALID) return ERR_INVALID_COMMAND_NAME;

    if (check_multiple_commas(input)) return ERR_MULTIPLE_COMMA;
    int index_comma= check_missing_commas(input);
    if (index_comma==2) return ERR_ILEGAL_COMMA;
    else if (index_comma==1) return ERR_MISSING_COMMA;

    int len = strlen(input);
    int k = len - 1;
    while (k >= 0 && isspace((unsigned char)input[k])) {
        k--;
    }
    if (k >= 0 && input[k] == ',') {
        return ERR_TEXT_AFT_END;
    }
    



    /*מקס 0*/
    if (strcmp(command, "stop") != 0 )
    {    
    if (arg1 == NULL) return ERR_MISSING_ARG;
    if (get_matrix_by_name(arg1) == NULL) return ERR_INVALID_MATRIX_NAME;
    }else
    {
        if (arg1 != NULL)
        {
            return ERR_TEXT_AFT_END;
        }
    }
    /*בכל הפקודות שצריך  מקס 1:*/
    if(strcmp(command, "print_mat") != 0 && strcmp(command, "stop") != 0 ){
        if (arg2 == NULL) return ERR_MISSING_ARG;            
        if (strcmp(command, "mul_scalar")==0)
        {
            if (!is_number(arg2)) return ERR_ARG_NOT_SCALAR;            
        }else if ( strcmp(command, "read_mat") != 0){
            if (get_matrix_by_name(arg2) == NULL) return ERR_INVALID_MATRIX_NAME;
        }
    }else
    {
        if (arg2 != NULL)
        {
            return ERR_TEXT_AFT_END;
        }
    }
    
    /*בכל הפקודות שצריך מקס 2 arg2:*/
    if(strcmp(command, "print_mat") != 0 &&  strcmp(command, "stop") != 0 && strcmp(command, "read_mat") != 0 && strcmp(command, "trans_mat") != 0){
        if (arg3 == NULL) return ERR_MISSING_ARG;
        if (get_matrix_by_name(arg3) == NULL) return ERR_INVALID_MATRIX_NAME;

        
    }else
    {
        if (arg3 != NULL)
        {
            return ERR_TEXT_AFT_END;
        }
    }
    /*  מקס 3*/
    if (arg4 != NULL)
    {
        return ERR_TEXT_AFT_END;
    }

    if (strcmp(command, "read_mat") == 0)
    {
        int i = 0;
        char str_copy[1000];
        strncpy(str_copy, arg2, sizeof(str_copy) - 1);
        str_copy[sizeof(str_copy) - 1] = '\0'; 
        char* token = strtok(str_copy, ",");
        while (token != NULL && i < SIZE_MAT) {
            trim_whitespace(token);
            if (is_number(token) == 0)
            {
                return ERR_ARG_NOT_NUM;
            }
            i++;
            token = strtok(NULL, ",");
        }
    }
return VALID;
}

int is_number(char* str) {
    int i = 0;
    int dot_count = 0;

    if (str[0] == '-' || str[0] == '+') {
        i++;
    }

    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dot_count++;
            if (dot_count > 1) {
                return 0;
            }
        } else if (!isdigit((unsigned char)str[i])) {
            return 0;
        }
    }

    return 1;
}

int check_multiple_commas(char* input) {
    int j;
    char copy_input[1000];
    strncpy(copy_input, input, sizeof(copy_input) - 1);
        copy_input[sizeof(copy_input) - 1] = '\0';
        input[strcspn(input, "\n")] = '\0';
    remove_whitespace(copy_input);
    for (j = 0; copy_input[j + 1] != '\0'; j++) {
        if (copy_input[j] == ',' && copy_input[j + 1] == ',') {
            return 1;
        }
    }
    return 0;
}

int check_missing_commas(const char* input) {
    int i = 0;
    int arg_index = 0;         
    int last_was_comma = 0;

    while (input[i] != '\0') {
        while (input[i] == ' ' || input[i] == '\t') {
            i++;
        }

        if (input[i] == '\0') break;

        arg_index++;

        if (arg_index == 1) {
            while (input[i] != '\0' && input[i] != ' ' && input[i] != '\t' && input[i] != ',' ) {
                
                i++;
            }
            while (input[i] == ' ' || input[i] == '\t') {
                i++;
            }
            if (input[i] == ',') {
                return 2;
            }
        

            continue;
        }
        printf("arg_index: %d, last: %d\n", arg_index,last_was_comma);
        if (!last_was_comma && arg_index >2) {
            return 1; 
        }

        while (input[i] != '\0' && input[i] != ' ' && input[i] != '\t' && input[i] != ',') {
            i++;
        }

        while (input[i] == ' ' || input[i] == '\t') {
            i++;
        }

        if (input[i] == ',') {
            last_was_comma = 1;
            i++;
        } else {
            last_was_comma = 0;
        }
    }

    return 0;
}