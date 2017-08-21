#include <stdio.h>

int main(void) {
  int a, b, c;
  
  printf("Please input the first number:\n");
  scanf("%d", &a);
  
  printf("Please input the first number:\n");
  scanf("%d", &b);
  
  printf("Please input the first number:\n");
  scanf("%d", &c);
  
  printf("You entered: %d, %d, &% d\n", a, b, c);
  
  if (a >= b) {
    if (b >= c) {
      printf("%d is the minimum value\n", c);
    }
    else {
      printf("%d is the minimum value\n", b);
    }
  }
  else {
    if (a >= c) {
      printf("%d is the minimum value\n", c);
    }
    else{
      printf("%d is the minimum value\n", a);
    }
  }
  
  return 0;
}
