// Joshua Luke R. Cordova	SN: 2015-90760

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>
#include <string.h>

void test_method(void);
void test_pair_finder(void);

void print_args(int argc, char*argv[]);
int sumdiv(int);
float isfriendly(int,int);
bool equality(float,float);
int pair_finder(float,int,int);

int main(int argc, char*argv[]) {
	//printf("argc = %d\n",argc);
	
	test_method();
	
	if (argc == 1) {
                printf("Usage: ./me7 <int1> (<int2> <int3>)\n");
                return -1;
        }
	
	if (argc > 3) {
		print_args(argc,argv);
		pair_finder(atof(argv[1]), atoi(argv[2]), atoi(argv[3]));
	}
	else if (argc == 3) {
		print_args(argc,argv);
		printf("isfriendly(%d, %d) = %f\n", atoi(argv[1]), atoi(argv[2]), isfriendly(atoi(argv[1]),atoi(argv[2])));
	}
	else if (argc == 2) {
		print_args(argc,argv);
		printf("sumdiv(%d) = %d\n", atoi(argv[1]), sumdiv(atoi(argv[1])));
	}
	else {
		printf("Usage: ./me7 <int1> (<int2> <int3>)\n");
		return -1;
	}
	return 0;
}

void print_args(int argc, char*argv[]) {
	int ctr = 1;
	for (ctr = 1; ctr < 4 && ctr < argc; ++ctr) {
                printf("argv[%d] = %s\n", ctr, argv[ctr]);
	}
}

void test_method(void){
	
	assert(sumdiv(24) == 36);
	assert(sumdiv(-15) == 0);
	
	assert(equality(isfriendly(30, 140), 1.4));
	assert(equality(isfriendly(10, 20), 0));
	
	//test_pair_finder(); // runs a  battery of asserts specifically for pair_finder
}

int sumdiv(int n) {
	if (n <=0) {
		return 0;
	}
	else {
		int i = 0;
		int sum = 0;
		double root = sqrt(n);
			for (i = 1; (i < root); i++) {
				//printf ("i = %d sum = %d\n", i , sum);
				if (i == 1) {
					sum += 1;
				}
				else if (n % i == 0) {	//divisibility check
					sum += i;
					sum += n/i;
				}
			}
		return sum;
	}
}

float isfriendly(int a, int b) {
	float flt_a = a;
	float flt_b = b;
	float ratio_a = sumdiv(flt_a)/flt_a;
	float ratio_b = sumdiv(flt_b)/flt_b;
	assert(equality(2,3) == false);
	assert(equality((7/3),(14/6)) == true);
	if ((a <= 0) || (b <= 0))
		return 0;
	else if ((a != b) && ( equality(ratio_a,ratio_b) )) {
		//printf("debug:\ta = %d\tsumdiv(a) = %d\tratio_a = %f\n\tb = %d\tsumdiv(b) = %d\tratio_b = %f\n", a, sumdiv(a), ratio_a, b, sumdiv(b), ratio_b);
		return ratio_a;
	}
	else {
		return 0;
	}
}

bool equality (float a, float b) {
	//printf("a = %f\tb = %f\tFLT_EPSILON = %f\n", a, b, FLT_EPSILON);
	return fabs(a - b) < FLT_EPSILON;
}

int pair_finder(float fr_ratio, int start_val, int end_val) {
	int i = 0, j = 0, pair_1 = 0, pair_2 = 0, pair_found = 0;
	printf("fr_ratio = %f\nstart_val = %d\nend_val = %d\n", fr_ratio, start_val, end_val);
	printf("running: pair_finder(%f, %d, %d)\n", fr_ratio, start_val, end_val);
	for (i = start_val; i <= end_val; i++) {
		for (j = i ;j <= end_val; j++) {
			//printf("i = %d\nj = %d\n isfriendly(i, j) = %f\n", i, j , isfriendly(i, j));
			if (isfriendly(i, j) > fr_ratio) {
				pair_1 = i;
				pair_2 = j;
				printf("\t(%d, %d)\n", pair_1, pair_2);
				pair_found += 1;
				char test_out[80];	//test output for assert comparison
				//sprintf(test_out, "(%d, %d)", pair_1, pair_2);
				//strncpy(test_out, ,strlen(test_out));
				puts(test_out);
				printf("pair_found == %d\n",pair_found);
				printf("strncmp(test_out,\"(6, 28)\", strlen(test_out)= %d", strncmp(test_out,"(6, 28)", strlen(test_out)));
				
				/*assert(
					(
					((equality(fr_ratio, 0)) && (start_val == 1) && (end_val == 100))
					&& ((pair_found == 1) && (strncmp(test_out,"(6, 28)", strlen(test_out) ) ))
					)
					||
					(
					((equality(fr_ratio, 1.9)) && (start_val == 10) && (end_val == 1000))
					&& ((pair_found == 1) && (strncmp(test_out,"(120, 672)", strlen(test_out) ) ))
					&& ((pair_found == 2) && (strncmp(test_out,"(240, 600)", strlen(test_out) ) ))
					&& ((pair_found == 3) && (strncmp(test_out,"(864, 936)", strlen(test_out) ) ))
					)
				);*/
			}
		}	
	}
	return pair_found;
}
/*
void test_pair_finder(void) {
	printf("\nstart assert debug...\n");
	assert(pair_finder(0, 1, 100) == 1);
	assert(pair_finder(1.9, 10, 1000) == 3);
	assert(pair_finder(0, 6, 140) == 2);
	printf("end assert debug.\n\n");
	
}
*/