#include "magic.h"

/*
Ensures the correct number of elements (N * N) has been entered.
*/
int check_amount_elements(int count) { 
    if (count == N*N) {
        return TRUE;
    }else if (count < N*N) {
        printf("Error: Too few numbers were received.Expected %d elements, but got %d.\n", N*N, count);
        return FALSE;
    }else {
        printf("Error: Too many numbers were received.Expected %d elements, but got more.\n", N*N);
        return FALSE;
    }   
}
/*
Print the matrix
*/
void print_matrix(int mat[N][N]) {
    int i,j;

    printf("\n");
	/*Print the matrix*/
	printf("The matrix you entered is:\n");
	for (i=0;i<N; i++)
		printf("\t[%d] ",i);
	printf("\n");
    

	for (i=0;i<N; i++) {
		printf("[%d]\t ",i);
        for (j=0;j<N;j++) {
            printf("%d\t ", mat[i][j]);
        }
        printf("\n");
    }
}
/*Validates if the input is an integer.
 If it is not, return FALSE. Otherwise, return TRUE.
 */
int is_int(int n) {
    if (n == 0) {
        printf("Error: an invalid character was received.\n");
        return FALSE;
    }
    return TRUE;
}

/*Checks if a number has already been entered in the matrix.
 If it has, return TRUE. Otherwise, return FALSE.
*/
int is_duplicate(int num, int *seen_numbers, int count) {
    int i;
    for (i = 0; i < count; i++) {
        if (seen_numbers[i] == num) {
            return TRUE; 
        }
    }
    return FALSE;
}
/*
 Checks if a number is outside the valid range (1 to N^2).
 */
int is_out_range(int n) {
    if (n > N*N || n < 1) {
        return TRUE;
    }
    return FALSE;
}
/*
Determines if the matrix is a magic square.
*/
int is_magic(int mat[N][N]) {
    int i,j;
    int sum = 0;
    int sum_diag1 = 0;
    int sum_diag2 = 0;
    int magic_sum = 0;
    /*Calculate the magic sum*/
    for (i=0;i<N;i++) {
        magic_sum += mat[0][i];
    }
    /*Check rows*/
    for (i=1;i<N;i++) {
        sum = 0;
        for (j=0;j<N;j++) {
            sum += mat[i][j];
        }
        if (sum != magic_sum) {
            return FALSE;
        }
    }
    /*Check columns*/
    for (i=0;i<N;i++) {
        sum = 0;
        for (j=0;j<N;j++) {
            sum += mat[j][i];
        }
        if (sum != magic_sum) {
            return FALSE;
        }
    }
    /*Check diagonals*/
    for (i=0;i<N;i++) {
        sum_diag1 += mat[i][i];
        sum_diag2 += mat[i][N-i-1];
    }
    if (sum_diag1 != magic_sum || sum_diag2 != magic_sum) {
        return FALSE;
    }
    return TRUE;
}