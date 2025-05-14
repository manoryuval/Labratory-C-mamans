#ifndef PARSER_H
#define PARSER_H
#include <stdio.h>
#include "mymat.h"
typedef enum {
    CMD_ADD,
    CMD_SUB,
    CMD_MUL,
    CMD_MUL_SCALAR,
    CMD_TRANS,
    CMD_READ,
    CMD_PRINT,
    CMD_STOP,
    CMD_INVALID
} CommandType;

typedef enum {
    VALID,
    ERR_INVALID_MATRIX_NAME,
    ERR_INVALID_COMMAND_NAME,
    ERR_ARG_NOT_NUM,
    ERR_TEXT_AFT_END,
    ERR_MISSING_ARG,
    ERR_ILEGAL_COMMA,
    ERR_MISSING_COMMA,
    ERR_MULTIPLE_COMMA,
    ERR_ARG_NOT_SCALAR,
} ValidationInput;

CommandType get_command_by_name(char* name);
void trim_whitespace(char* str);
void remove_whitespace(char* str);
ValidationInput validator(char* input,char* command, char* arg1, char* arg2, char* arg3, char* arg4);
int is_number(char* str);
int check_multiple_commas(char* input);
int check_missing_commas(const char* input);



#endif
