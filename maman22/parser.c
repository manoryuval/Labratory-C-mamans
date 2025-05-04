#include <string.h>
#include "parser.h"

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
