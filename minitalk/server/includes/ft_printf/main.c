#include "printf.h"
#include <stdio.h>

int main()
{
  //          1  2  3  4  5  6  7  8 9  10 11 12 13 14 15
  char *s = " %34d ";
  // unsigned long int c = -1;
  printf("\n\nprintf\n");
  int result = 0;//printf(s, 'A');
  printf("\n\nPRINTF\n");
  int result_printf = printf(s, 357);
  printf("\nResult: %d, %d\n", result, result_printf);
  return (0);
}
