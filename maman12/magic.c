#include "magic.h"

typedef int mat[N][N];/*magic matrix, size N*/
/**

*/
int main() {
	int i,j,n,a;
    int seen_numbers[N*N]; /*array to check if there are duplicate numbers*/    
    int count=0;
    int samenum = FALSE; /*flag to check if there is same numbers in the matrix*/
    int outrange = FALSE; /* flag to check if number is out of range 1>N^2*/
	mat mat;
	/*Get the elements of matrix. row by row*/
 	printf("Please enter the elements of a %d x %d matrix:\n", N,N );	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
            if ((a=scanf("%d",&mat[i][j]))!= EOF)
            {
                if (!samenum  && is_duplicate(mat[i][j], seen_numbers, count)) {
                    samenum = TRUE;
                }
                seen_numbers[count] = mat[i][j];
                if (is_int(a) == FALSE) {
                    return FALSE;
                }
                if (is_out_range(mat[i][j])){
                    outrange = TRUE;
                }
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
	
    if (is_magic(mat) && samenum == FALSE && outrange == FALSE) {
            printf("The matrix is a magic square.\n");
    } else if  (samenum == TRUE) {
        printf("The matrix is NOT a magic square. There are duplicate numbers in the matrix.\n");
        return FALSE;
    } else if (outrange == TRUE) {
        printf("The matrix is NOT a magic square. One or more numbers are out of range.\n");
        return FALSE;
    } else {
        printf("The matrix is NOT a magic square.\n");
    }
   

	return FALSE;
}

