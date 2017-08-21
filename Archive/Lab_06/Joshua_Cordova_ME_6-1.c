#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main() {
  
  int x, sum = 0, i, b = 0;
  double dblsum, sr;
  char c;
  
  c = getchar();
  for (;c != '\n';) {
    x = atoi(&c);
    if (isdigit(c)) {
      sum += x;
    }
    //printf ("c = %c x = %d sum = %d\n", c, x, sum);
    c = getchar();
  }
  dblsum = sum;
 
  sr = sqrt(dblsum);
  //printf("sr = %f\n", sr);
  
  for (i = 2; (i < sr) || sr < 1; i++) {
    //printf ("i = %d sum = %d\n", i , sum);
    if (sum % i == 0){
      //printf("%d is composite\n", sum);
      b = 1;
      break;
    }
    else {
      continue;
    }
  }
  
  //printf("b = %d\n", b);
  if (!b){
    printf("%d is prime\n", sum);
  }
return 0;
}