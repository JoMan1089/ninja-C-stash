#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *pVar = 0;
	int iVar = 2016;
	pVar = &iVar;
	printf("%d\n", iVar);
	printf("%d\n", *pVar);
	*pVar = 24601;
	printf("%d\n", iVar);
	printf("%d\n", *pVar);
	return 0;        
}