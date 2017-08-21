#include <stdio.h>

int main(void) {
  char a;
  printf("Please input a keypress:\n");
  scanf("%c", &a);
  
  if ((a >= 48) && (a <= 57)) {
    printf("%c is a number\n", a);
  }
  else if (((a >= 65) && (a <= 90)) || ((a >= 97) && (a <= 122))) {
    printf("%c is a letter\n", a);
  }
  else {
    printf("%c is a symbol\n", a);
  }
  
 return 0;
}