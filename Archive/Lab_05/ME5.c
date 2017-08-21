#include <stdio.h>

int main(void)
{
  int c, count = 0;
	c = getchar();
  for (; c != '\n';) {
    if ((c == 'L') || (c == 'l')) {
			c = getchar();
      if ((c == 'O') || (c == 'o')) {
				c = getchar();
        if ((c == 'V') || (c == 'v')) {
					c = getchar();
					if ((c == 'E') || (c == 'e')) {
            count += 1;
          }
        }
      }
		} 
		else
			c = getchar();
  }
  printf ("You found love %d time(s): \n", count);
  return 0;
}