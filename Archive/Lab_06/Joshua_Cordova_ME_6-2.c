#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int a, b, up = -1;
	
  for (b = getchar();b != '\n'; a = b, b = getchar()) {
    if ((b >= 48) && (b <= 57)) {
	    printf("a = %c b = %c\n", a, b);
	    if ((a == b) || !((a >= 48) && (a <= 57))){
			continue; 
			}
			else if (a < b) {
				printf("a < b\n");
				if (up == 0) {
					printf("Bouncy\n");
					return 0;
				}
				up = 1;
			}
			else {
				printf("a > b\n");
				if (up == 1) {
					printf("Bouncy\n");
					return 0;
				}
				up = 0;
			}
    }
		else if ((a >= 48) && (a <= 57)) {
			printf("Bad Input\n");
			return 0;
		}
	  else {
			printf("Bad Input\n");
			return 0;
		}	
  }
	if (up == 1){
		printf("Increasing\n");
	}
	else 
		printf("Decreasing\n");
		
	return 0;
}