#include "ft_printf.h"
#include <stdio.h>

int main()
{
  char *s = "%d";
  int c = -2000000000;
  int result = ft_printf(s, c);
  int result_printf = printf(s, c);
  printf("\nResult: %d, %d\n", result, result_printf);
  return (0);
}
