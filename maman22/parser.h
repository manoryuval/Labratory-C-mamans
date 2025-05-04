#ifndef PARSER_H
#define PARSER_H

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

CommandType get_command_by_name(char* name);

#endif
