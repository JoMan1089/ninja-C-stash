#include <stdio.h>

int main(void)
{
  int a, b, q, r;
  printf("Please Input 2 integers: \n");
  scanf("%d %d", &a, &b);
 
  q = a/b;
  r = a%b;
    
  // printf("Debug: %d \t %d \t %d \t %d \n", a, b, q, r);
  
  printf("%d/%d = %d Remainder: %d\n", a, b, q, r);
  return 0;
}