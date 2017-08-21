#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
	printf("%d\n",argc);
	if (argc>3){
		printf("%d\n%d\n%d\n", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	}
	else return -1;
	return 0;
}