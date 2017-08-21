#include <stdio.h>

int main (void)
{
  printf("Strings\n");
  const char* s = "Hello";
  printf("\t.%10s.\n\t.%-10s.\n\t.\*s.\n", s ,s ,10 ,s);
  
  printf("Characters:\t%c 83\n", 65);
  printf("Integers\n");
  printf("Decimal\t%i %d %.6i %i %.0i %+i %u\n", 1, 2, 3, 0, 0, 4, -1);
  printf("Hexadecimal:\t%x %x %X %#x\n", 5, 10, 10, 6);
  printf("Octal:\t%o %#o \n", 10, 10, 4);
  
  printf("Floating point\n");
  printf("Rounding:\t%f %.0f %.32")
}