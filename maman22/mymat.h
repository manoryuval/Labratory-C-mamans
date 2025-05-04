typedef double mat[4][4];

extern mat MAT_A;
extern mat MAT_B;
extern mat MAT_C;
extern mat MAT_D;
extern mat MAT_E;
extern mat MAT_F;

int to_zero_mat(mat A);
mat* get_matrix_by_name(char* name);

int read_mat(char* mat_name, char* values_str);
int print_mat(mat A);
int add_mat(mat A, mat B, mat C);
int sub_mat(mat A, mat B, mat C);
int mul_mat(mat A, mat B, mat C);
int mul_skalar(mat A,double x, mat B);
int trans_mat(mat A, mat B);
void stop();