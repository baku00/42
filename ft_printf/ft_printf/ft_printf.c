#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int  ft_printf(const char *s, ...)
{
  int i;
  int c_counter;
  int n;
  char  *string;
  va_list args;

  va_start(args, s);
  i = 0;
  c_counter = 0;
  while (s[i])
  {
    if (s[i] == '%')
    {
      i++;
      if (s[i] == 'c')
      {
        c_counter++;
        ft_print_c(va_arg(args, int));
      }
      else if (s[i] == 'd' || s[i] == 'i')
      {
        n = va_arg(args, int);
        c_counter += ft_intlen(n);
        ft_print_d(n);
      }
      else if (s[i] == 'p')
      {
        n = va_arg(args, long int);
        c_counter += ft_intlen(n) + 2;
        ft_print_p(n);
      }
      else if (s[i] == 's')
      {
        string = va_arg(args, char *);
        if (!string)
          string = "(null)";
        c_counter += ft_strlen(string);
        ft_print_s(string);
      }
      else if (s[i] == 'u')
      {
        ft_print_u(va_arg(args, unsigned int));
      }
      else if (s[i] == 'x')
        ft_print_x(va_arg(args, int));
      else if (s[i] == '%')
        ft_print_c('%');
    }
    else
    {
      c_counter++;
      ft_print_c(s[i]);
    }
    i++;
  }
  va_end(args);
  return (c_counter);
}
