#include "mymat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){

    to_zero_mat(MAT_A);
    to_zero_mat(MAT_B);
    to_zero_mat(MAT_C);
    to_zero_mat(MAT_D);
    to_zero_mat(MAT_E);
    to_zero_mat(MAT_F);
    read_mat("MAT_A", "1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16");
    read_mat("MAT_B", "1,1,1,1,1,1,1,1,1,1,1,1");
    print_mat(MAT_A);
    print_mat(MAT_B);
    sub_mat(MAT_A, MAT_B, MAT_C);
    mul_mat(MAT_A, MAT_B, MAT_D);
    mul_skalar(MAT_A, 2, MAT_E);
    trans_mat(MAT_A, MAT_F);
    printf("Subtraction:\n");
    print_mat(MAT_C);
    printf("Multiplication:\n");
    print_mat(MAT_D);
    printf("Multiplication by scalar:\n");
    print_mat(MAT_E);
    printf("Transpose:\n");
    print_mat(MAT_F);
    stop();
    printf("didnt stop:\n");

    return 0;

}