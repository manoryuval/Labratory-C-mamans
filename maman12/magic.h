#ifndef MAGIC_H 
#define MAGIC_H
#include <stdio.h>

#define N 5 /*Size of the matrix*/  
#define TRUE 1
#define FALSE 0


int check_amount_elements(int count);
void print_matrix(int mat[N][N]);
int is_int(int n);
int is_duplicate(int num, int *seen_numbers, int count);
int is_out_range( int n);
int is_magic(int mat[N][N]);





#endif