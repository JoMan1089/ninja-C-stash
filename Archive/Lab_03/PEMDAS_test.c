#include <stdio.h>

int main(void)
{
  int a;
  int b;
  int c;
  printf("Please Input 3 integers: \n");
  scanf("%d %d %d", &a, &b, &c);
 
  int ans;
  ans = a * (b-c);
    
  // printf("Debug: %d \t %d \t %d \n", a, b, c);
  
  printf("%d * (%d - %d) = %d \n", a, b, c, ans);
  return 0;
}