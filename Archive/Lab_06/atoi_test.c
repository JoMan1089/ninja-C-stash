#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int i;
	char c;
	
	c = getchar();
	
	i = atoi(&c);
	
	printf("%d %c %x\n", i, i, i);
	
	return 0;
}