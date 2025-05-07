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
        if (arg1 == NULL) return ERR_MISSING_ARG;            
        if (get_matrix_by_name(arg1) == NULL) return ERR_INVALID_MATRIX_NAME;
    }else
    {
        if (arg2 != NULL)
        {
            return ERR_TEXT_AFT_END;
        }
    }
    
    /*בכל הפקודות שצריך מקס 2 arg2:*/
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
        if (arg3 != NULL)
        {
            return ERR_TEXT_AFT_END;
        }
    }


    /*  מקס 3*/
    if(strcmp(command, "print_mat") != 0 && strcmp(command, "read_mat") != 0 && strcmp(command, "trans_mat") != 0 && strcmp(command, "stop") != 0){
        if (arg3 == NULL) return ERR_MISSING_ARG;
        if (get_matrix_by_name(arg3) == NULL) return ERR_INVALID_MATRIX_NAME;
    }else
    {
        if (arg4 != NULL)
        {
            return ERR_TEXT_AFT_END;
        }
    }

    if (strcmp(command, "read_mat") == 0)
    {
        int i = 0;
        char str_copy[1000];
        strncpy(str_copy, arg2, sizeof(str_copy) - 1);
        str_copy[sizeof(str_copy) - 1] = '\0'; 
        char* token = strtok(str_copy, ",");
        while (token != NULL && i < SIZE_MAT) {
            if (is_number(token) == 0)
            {
                return ERR_ARG_NOT_NUM;
            }
            i++;
            token = strtok(NULL, ",");
        }
    }

    /*( זה צריך להיות בהתחלה) לסווג כמוץ פסיקים לפי פקודות ולבדוק*/



return VALID;
}
/*
פסיק במקום לא חוקי
*/
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

int count_commas(char* str) {
    int count = 0;
    while (*str) {
        if (*str == ',') {
            count++;
        }
        str++;
    }
    return count;
}

/*

if (strstr(input, ",,") != NULL) {
        return ERR_MULTIPLE_COMMA;
    }
    int len = strlen(input);
    if (input[len - 1] == ',') {
        return ERR_TEXT_AFT_END;
    }
    if( count_commas(input) > 0) {
        return ERR_MULTIPLE_COMMA;
    }
}
*/