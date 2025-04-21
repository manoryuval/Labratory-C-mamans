#include "magic.h"



int check_amount_elements(int count) { 
    if (count == N*N) {
        return TRUE;
    }else if (count < N*N) {
        printf("Error: Too few numbers were received.Expected %d elements, but got %d.\n", N*N, count);
        return FALSE;
    }else {
        printf("Error: Too many numbers were received.Expected %d elements, but got %d.\n", N*N, count);
        return FALSE;
    }   
}

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
int check_int(int n) {
    if (n == 0) {
        printf("Error: an invalid character was received.\n");
        return FALSE;
    }
    return TRUE;
}

int duplicate_num(int num, int *seen_numbers, int count) {
    int i;
    for (i = 0; i < count; i++) {
        if (seen_numbers[i] == num) {
            return TRUE; 
        }
    }
    return FALSE;
}
int num_out_range(int n) {
    if (n > N*N || n < 1) {
        return TRUE;
    }
    return FALSE;
}