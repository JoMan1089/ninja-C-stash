#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool is_modulo(int,int);
int sum(int);

int main() {
	//debug code
	int test_int;
	assert(is_modulo(3,3)==true);
	assert(is_modulo(5,5)==true);
	
	test_int = sum(3);
	printf("%d\n",test_int);
	assert(sum(3)==3);
	assert(sum(5)==8);
	
	test_int = sum(16);
	assert(test_int==(3+5+6+9+10+12+15));
	printf("test_int = %d; (3+5+6+9+10+12+15) = %d ", test_int, (3+5+6+9+10+12+15));
	
	int ans;
	ans = sum(1000);
	printf("\tthe sum of all the multiples of 3 & 5 below 1000 is: %d\n", ans);
	return 0;
}

bool is_modulo(int mod, int n) {
	if (n % mod == 0) {
		return true;
	}
	else {
		return false;
	}
}
int sum(int max_val) {
	int sum = 0, i;
	//printf("running sum(%d)\n",max_val);
	for (i = 0; i <= max_val; i++) {
		//printf("\ti = %d\n", i);
		if (is_modulo(3,i) || is_modulo(5,i)) {
			//printf("\tMod 3: %d\n\tMod 5: %d\n", is_modulo_3(i), is_modulo_5(i));
			sum += i;
			// printf("\tsum = %d\n\n", sum);
		}
	}
	return sum;
}
