#include <stdio.h>
#include <ctype.h>

int main()
{
	
	int o;
	char c;
	
	c = getchar();
	
	o = isdigit(c);
	
	printf("%d %c %x\n", o, o ,o);
	
	return 0;
}