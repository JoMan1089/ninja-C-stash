#include <stdio.h>

int main(void)
{
  char a;
  printf("Input character: \n");
  scanf("%c", &a );
  printf("You gave: %c\n\nASCII value:\n\tDecimal: %d\n\t Hexadecimal: %x\n", a, a, a);
  return 0;
}