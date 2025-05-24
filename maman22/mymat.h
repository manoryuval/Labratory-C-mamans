typedef double mat[4][4];/* Defines a matrix type as a 4x4 array of doubles */

extern mat MAT_A;
extern mat MAT_B;
extern mat MAT_C;
extern mat MAT_D;
extern mat MAT_E;
extern mat MAT_F;

#define MAX_INPUT 100 /*Maximum number of characters allowed in a single line of input */
#define SIZE_MAT 16 /*Total number of elements in a 4x4 matrix (4 * 4) */

/*Sets all elements of the matrix to zero. */
int to_zero_mat(mat A);
/*Maps a matrix name string to a mat enum.*/
mat* get_matrix_by_name(char* name);
/*Parses a comma separated string of values into matrix*/
int read_mat(mat m, char* values_str);
/*Prints the contents of matrix A to stdout*/
int print_mat(mat A);
/*Computes C = A + B */
int add_mat(mat A, mat B, mat C);
/*Computes C = A – B*/
int sub_mat(mat A, mat B, mat C);
/*Computes C = A × B*/
int mul_mat(mat A, mat B, mat C);  
/*Computes B = A × x (scalar)*/
int mul_skalar(mat A,double x, mat B);
/*Computes B = transpose(A)*/
int trans_mat(mat A, mat B);
/*Stops the program */
void stop();