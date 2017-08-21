#include <stdio.h>
int main() {
	int l = 0, o = 0, v = 0, e = 0, ctr = 0;
	for (e = getchar(); e != '\n'; l = o, o = v, v = e, e = getchar())
		if ((l == 'L' || l == 'l') && (o == 'O' || o == 'o') && (v == 'V' || v == 'v') && (e == 'E' || e == 'e'))
			ctr++;
	printf("You found love %d times\n", ctr);	
	return 0;
}