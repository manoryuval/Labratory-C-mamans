#ifndef PARSER_H
#define PARSER_H
#include <stdio.h>
#include "mymat.h"

/* Enum representing all valid command types the parser recognizes */
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

/* Enum representing possible validation outcomes for input parsing */
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


/*Returns the corresponding CommandType enum for a given command string */
CommandType get_command_by_name(char* name);

/* Trims leading and trailing whitespace from the given string */
void trim_whitespace(char* str);

/* Removes all whitespace characters from the given string */
void remove_whitespace(char* str);

/*
 Parses and validates the input string.
 Extracts the command and up to four arguments into provided buffers.
 Returns a ValidationInput code indicating the result.
 */
ValidationInput validator(char* input, char* command, char* arg1, char* arg2, char* arg3, char* arg4);

/* Returns 1 if the string represents a valid number, otherwise 0 */
int is_number(char* str);

/* Checks for multiple consecutive commas in the input string */
int check_multiple_commas(char* input);

/* Checks if there are missing commas between arguments */
int check_missing_commas(const char* input);

#endif