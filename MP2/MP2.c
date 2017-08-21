/*
 * MP2 - Linear Programming/Linear Optimization
 * Created by: Joshua Luke R. Cordova
 * Student Number: 2015-90760
 */

#include "matrix.h"
#include "string_ext.h"

void print_args(int argc, char *argv[]);
bool is_txt_file(char str[], size_t len);

//int main(int argc, char *argv[])
int main()
{
	//printf("argc = %d\n",argc);
	//print_args(argc, argv);
	
	/*
	if (argc == 2) {
		if (is_txt_file( argv[1], strlen(argv[1]) )) {
			printf("Attempting to open file\n");
			FILE *fp = fopen(argv[1], "r");
			if (!fp){
				printf("Error: Unable to open file\n");
				return -1;
			}
			else
				printf("Successfully opened %s\n", argv[1]);
			
			
			fclose(fp);
		}
		else
			printf("Please input a text file\n");
	}
	else {
		printf("Usage: ./mp2 problem_file.txt\n");
	}
	*/
	
	mat_t test_mat1 = {0, 0, NULL};
	mat_t *mat_nav1 = &test_mat1;
	mat_malloc(mat_nav1, 3, 4);
	
	mat_nav1->matrix[0][0] = 23;
	mat_nav1->matrix[2][3] = 12;
	scale_mat(mat_nav1, 4);
	print_mat(mat_nav1);
	
	mat_t test_mat2 = {0, 0, NULL};
	mat_t *mat_nav2 = &test_mat2;
	mat_malloc(mat_nav2, 3, 4);
	mat_nav2->matrix[2][0] = 45;
	mat_nav2->matrix[2][3] = 56;
	print_mat(mat_nav2);
	scale_mat(mat_nav2, 1/4);
	print_mat(mat_nav2);
	
	mat_t test_mat3 = {0, 0, NULL};
	mat_t *mat_nav3 = &test_mat3;
	mat_malloc(mat_nav3, 3, 4);
	subt_mat(mat_nav1, mat_nav2, mat_nav3);
	printf("%zu\n", mat_nav3->i);
	print_mat(mat_nav3);
	
	mat_free(mat_nav1);
	mat_free(mat_nav2);
	mat_free(mat_nav3);
	return 0;
}

void print_args(int argc, char *argv[])
{
	int ctr;
	for (ctr = 0; ctr < argc - 1; ++ctr) {
		printf("argv[%d] = %s\n", ctr, argv[ctr]);
	}
}
/*
bool is_txt_file(char str[], size_t len)
{
	size_t pos;
	pos = str_search(str, '.', len);
	//printf("index of '.' = %zu\n", pos);
	if (pos != -1) {
		char *cp = &str[pos];
		//puts(cp);
		if ( strncmp(cp, ".txt", strlen(".txt")) == 0 ) { // if str = ".txt" return true
			return true;
		}
	}
	return false;
}
*/