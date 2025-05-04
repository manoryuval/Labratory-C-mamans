#include "mymat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
mat MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F;


int to_zero_mat(mat A){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            A[i][j]=0;
        }
    }
    return 0;
}
mat* get_matrix_by_name( char* name) {
    if (strcmp(name, "MAT_A") == 0) return &MAT_A;
    if (strcmp(name, "MAT_B") == 0) return &MAT_B;
    if (strcmp(name, "MAT_C") == 0) return &MAT_C;
    if (strcmp(name, "MAT_D") == 0) return &MAT_D;
    if (strcmp(name, "MAT_E") == 0) return &MAT_E;
    if (strcmp(name, "MAT_F") == 0) return &MAT_F;
    return NULL;
}

int read_mat(mat m, char* values_str) {
    int row, col;
    int i = 0;
    double val;
    char str_copy[1000];
    strncpy(str_copy, values_str, sizeof(str_copy) - 1);
    str_copy[sizeof(str_copy) - 1] = '\0'; 

    if (values_str == NULL) 
        return 1;
    printf("values_str: %s\n", values_str);
    printf("str_copy: %s\n", str_copy);
    char* token = strtok(str_copy, ",");
    printf("token: %s\n", token);
    while (token != NULL && i < SIZE_MAT) {
        val = atof(token);
        row = i / 4;
        col = i % 4;
        m[row][col] = val;
        i++;
        token = strtok(NULL, ",");
    }
    return 0;
}

int print_mat(mat A){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%.2f ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int add_mat(mat A, mat B, mat C){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    return 0;
}

int sub_mat(mat A, mat B, mat C){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            C[i][j]=A[i][j]-B[i][j];
        }
    }
    return 0;
}

int mul_mat(mat A, mat B, mat C) {
    int i, j, k;
    mat temp;

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            temp[i][j] = 0;
            for (k = 0; k < 4; ++k) {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            C[i][j] = temp[i][j];
        }
    }
    return 0;
}

int mul_skalar(mat A,double x, mat B){
    int i, j;
    mat temp;

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            temp[i][j] = A[i][j] * x;
        }
    }

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            B[i][j] = temp[i][j];
        }
    }
    return 0;
}

int trans_mat(mat A, mat B){
    int i, j;
    mat temp;

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            temp[j][i] = A[i][j];
        }
    }

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            B[i][j] = temp[i][j];
        }
    }
    return 0;
}
void stop() {
    exit(0);
}