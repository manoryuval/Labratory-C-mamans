#include "magic.h"

typedef int mat[N][N];/*magic matrix, size N*/
/**

*/
int main() {
	int i,j,n;
    int count=0;
	mat mat;
	/*Get the elements of matrix. row by row*/
 	printf("Please enter the elements of a %d x %d matrix:\n", N,N );	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
            if (scanf("%d",&mat[i][j])!= EOF)
            {
                count++;
            }
        }
    }
    if (scanf("%d",&n)!= EOF)
    {
        count++;
    } 
    if (!check_amount_elements(count)) {
        return FALSE;
    }
   
    /*Print the elements of the matrix*/
    print_matrix(mat);
	
	return FALSE;
}

