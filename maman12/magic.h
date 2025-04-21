#ifndef MAGIC_H 
#define MAGIC_H
#include <stdio.h>

#define N 3 /*Size of the matrix*/  
#define TRUE 1
#define FALSE 0


int check_amount_elements(int count);
void print_matrix(int mat[N][N]);
int check_int(int n);
int duplicate_num(int num, int *seen_numbers, int count);
int num_out_range( int n);





#endif