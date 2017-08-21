#include <stdio.h>

int main(void) {
  float a, grade;
  printf("Please Input Raw Grade:\n");
  scanf("%f", &a);
  if (a >= 92) {
    grade = 1;
  }
  else if ((a >= 88) && (a < 92)) {
    grade = 1.25;
  }
  else if ((a >= 84) && (a < 88)) {
    grade = 1.5;
  }
  else if ((a >= 80) && (a < 84)) {
    grade = 1.75;
  }
  else if ((a >= 76) && (a < 80)) {
    grade = 2;
  }
  else if ((a >= 72) && (a < 76)) {
    grade = 2.25;
  }
  else if ((a >= 68) && (a < 72)) {
    grade = 2.5;
  }
  else if ((a >= 64) && (a < 68)) {
    grade = 2.75;
  }
  else if ((a >= 60) && (a < 64)) {
    grade = 3;
  }
  else if (a < 60) {
    grade = 5;
  }
  else {
    printf("Error: Input not Recognized\n");
    return 0;
  }
  
  printf("%f --> %.2f\n", a, grade);
  
return 0;
}