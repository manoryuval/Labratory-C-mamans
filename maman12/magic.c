#include "magic.h"

typedef int adjmat[N][N];/*magic matrix, size N*/
/**

*/
int main() {
	int i,j;
    int count=0;
	adjmat mat;
	/*Get the elements of matrix. row by row*/
 	printf("Please enter the elements of a %d x %d matrix:\n", N,N );	
	for(i=0;i<N;i++){
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
return 0;   
}

