#include "magic.h"



int check_amount_elements(int count) { 
    if (count == N*N) {
        return TRUE;
    }else if (count < N*N) {
        printf("Error: Too few numbers were received.Expected %d elements, but got %d.\n", N*N, count);
        return FALSE;
    }else if (count > N*N) {
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