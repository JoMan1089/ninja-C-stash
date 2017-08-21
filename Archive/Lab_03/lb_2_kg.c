#include <stdio.h>
#define convert_kg_lb (2.205)

int main(void)
{
  float lb, kilo;
  printf("Pounds to Kilograms Converter: \n\nPlease input pound value: \n");
  scanf("%f", &lb);
 
  kilo = lb / convert_kg_lb;
    
  //printf("Debug:%f\t%f\t\n\n", lb, kilo);
  
  printf("%flb = \n\tTo 3 Decimal Places: %0.3fkg\n\tIn Scientific Notation: %.03ekg\n", lb, kilo, kilo);
  return 0;
}