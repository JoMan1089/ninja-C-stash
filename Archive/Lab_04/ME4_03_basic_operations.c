#include <stdio.h>

int main(void) {
  float a, b, ans;
  char o;
  
  printf("Please enter an expression:\n");
  scanf( "%f %c %f", &a, &o, &b);
  
  if (o == '+') {
    ans = a + b;
    printf("%f %c %f = %f\n", a, o, b, ans);
  }
  else if (o == '-') {
    ans = a - b;
    printf("%f %c %f = %f\n", a, o, b, ans);
  }
  else if (o == '*') {
    ans = a * b;
    printf("%f %c %f = %f\n", a, o, b, ans);
  }
  else if (o == '/') {
    ans = a / b;
    printf("%f %c %f = %f\n", a, o, b, ans);
  }
  else {
    printf("Unknown operation\n");
  }
return 0;
}
