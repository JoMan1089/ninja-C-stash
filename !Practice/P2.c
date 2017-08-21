#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

long fibonacci(long);
bool is_even(long);
long sum(long);

int main() {
	assert(fibonacci(0) == 1);
	assert(fibonacci(1) == 1);
	assert(fibonacci(5) == 8);
	assert(is_even(fibonacci(4)) == false);
	assert(is_even(fibonacci(5)) == true);
	assert(is_even(fibonacci(7)) == false);
	
	long ans = sum(4000000);
	printf("sum of all the even fibonacci numbers below 4,000,000 = %ld\n", ans);
	return 0;
}

long fibonacci(long n) {
	//printf("running fibonacci(%ld)\n", n);
	long prev = 0, curr = 1, next = 0, i;
	for (i = 1;i <= n; i++, prev = curr, curr = next){
		next = prev + curr;
		//printf("\ti = %ld\ti <= n: %d\n\tprev = %ld\tcurr = %ld\tnext = %ld\n", i, i <= n, prev, curr, next);
	}
	//printf("return %ld\n", curr);
	return curr;
}

bool is_even(long n) {
	if (n % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}

long sum(long max_val) {
	long sum = 0, i;
	//printf("running sum(%ld)\n",max_val);
	for (i = 0; fibonacci(i) <= max_val; i++) {
		//printf("\ti = %ld\n", i);
		printf("%ld\n", fibonacci(i));
		if (is_even(fibonacci(i))) {
			sum += fibonacci(i);
			//printf("\tsum = %ld\n\n", sum);
		}
	}
	return sum;
}