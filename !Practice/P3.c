#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
	unsigned long pair_1;
	unsigned long pair_2;
} pair_n;

void prime_factor(long);

int main() {
	prime_factor(600851475143);
	
	return 0;
}

void prime_factor(long num) {
	int i = 0;
	pair_n factors;
	double root = sqrt(num);
	//printf("sqrt(num) = %lf\n", root);
	for (i = 2; i <= root; i++) {
		//printf("i = %d\n", i);
		if (num % i == 0) {
			factors.pair_1 = i;
			factors.pair_2 = num/i;
			printf("%lu, %lu\n", factors.pair_1, factors.pair_2);
			prime_factor(factors.pair_2);
			printf("The largest prime factor of the number 600851475143 is %lu\n", factors.pair_2);
			return;
		}
	}
	return;
}