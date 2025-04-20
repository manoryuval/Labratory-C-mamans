#include <stdio.h>

#define N 3/*Matrix size*/
#define TRUE 1
#define FALSE 0

typedef int adjmat[N][N];/*magic matrix, size N*/
int check_amount_elements(int count);/*Function check the amount of elements that received*/
/**
 The program prompts the user to input an adjacency matrix.
* Then, accepts two indices from the user and checks if a path exists between them.
* The program continues to accept indices until the user inputs -1 for both indices, at which point it exits.

*/
int main() {
	int u,v,i,j;
    int count=0;
	adjmat mat;
	/*Get the elements of matrix. row by row*/
 	printf("Please enter the elements of a %d x %d matrix (row by row):\n", N,N );	
	for(i=0;i<N;i++){
		printf("Enter element at row [%d]: ", i + 1);
		for(j=0;j<N;j++){
		scanf("%d",&mat[i][j]);
        count++;
		}
	}
    if (!check_amount_elements(count)) {
        return 1;
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
	return FALSE;
}
int check_amount_elements(int count) { 
    if (count == N*N) {
        return 1;
    }else if (count < N*N) {
        printf("Error: Too few numbers were received.Expected %d elements, but got %d.\n", N*N, count);
        return 0;
    }else {
        printf("Error: Too many numbers were received.Expected %d elements, but got %d.\n", N*N, count);
        return 0;
    }
    
}
}