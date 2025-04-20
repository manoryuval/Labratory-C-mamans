#include <stdio.h>

#define N 3/*Matrix size*/
#define TRUE 1
#define FALSE 0

typedef int adjmat[N][N];/*Adjacency matrix, size N*/

int path( adjmat mat,int u,int v);
/** The program prompts the user to input an adjacency matrix.
* Then, accepts two indices from the user and checks if a path exists between them.
* The program continues to accept indices until the user inputs -1 for both indices, at which point it exits.

*/
int main() {
	int u,v,i,j;
	adjmat mat;
	/*Get the elements of matrix. row by row*/
 	printf("Please enter the elements of a %d x %d matrix (row by row):\n", N,N );	
	for(i=0;i<N;i++){
		printf("Enter element at row [%d]: ", i + 1);
		for(j=0;j<N;j++){
		scanf("%d",&mat[i][j]);
		}
	}
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
	/*Accepts two indices and checks if a path exists between them.
	Continues to accept indices until the user inputs -1 for both indices*/
	while(1){
		printf("Please enter two indices in the matrix to check if a path exists between them (enter -1 for both to exit):\n");
		if(scanf("%d%d",&u,&v) == EOF||(u==-1 && v==-1))
			break;
		if (path(mat, u, v))
        	printf("There is a path between %d and %d.\n", u, v);
    	else
        	printf("No path exists between %d and %d.\n", u, v);
	}
	return 0;
}
/*This function Checks if a path exists between two nodes in an adjacency matrix.

mat - The adjacency matrix
u - The starting node index
v- The target node index.
return 1 (TRUE) if a path exists between nodes u and v, 0 (FALSE) otherwise.
 */
int path( adjmat mat,int u,int v){
	int i;
	if (u>=N||v>=N)/*if the indeces are not in the matrix*/
		return FALSE;	
	if (u==v)/*if the start and target nodes are the same*/
		return TRUE;
	for(i=0;i<N;i++){/*run over all possible neighbors of the current node*/
		if(mat[u][i]==1){ /*if path exists, check if through this node path to  target node exists */
			if (path(mat, i, v)) 
                return TRUE;
		}

	}
	return FALSE;
}