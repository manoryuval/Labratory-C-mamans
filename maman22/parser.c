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
