#include "ft_printf.h"

static char *ft_get_base_string(int n, int base)
{
  int i;
  int h;
  char  *string;

  i = 0;
  string = ft_calloc(13, sizeof(char *));
  while (n > 0) {
    if (n > base)
    {
      h = n / 16;
      if (h >= 10)
      {
        if (h == 10)
          h = 'a';
        else if (h == 11)
          h = 'b';
        else if (h == 12)
          h = 'c';
        else if (h == 13)
          h = 'd';
        else if (h == 14)
          h = 'e';
        else if (h == 15)
          h = 'f';
      }
    }
    else
      h = '0';
    string[i++] = h;
    n--;
  }
  return (string);
}

int ft_printf(const char *s, ...)
{
  int i;
  va_list args;

  i = 0;
  va_start(args, s);
  while (s[i])
  {
    if (s[i] == '%' && s[i + 1])
    {
      if (s[i + 1] == 'c')
        ft_putchar_fd(va_arg(args, int), 1);
      else if (s[i + 1] == 's')
        ft_putchar_fd(*va_arg(args, char *), 1);
      else if (s[i + 1] == 'd' || s[i + 1] == 'i')
        ft_putnbr_fd(va_arg(args, int), 1);
      else if (s[i + 1] == 'x')
        ft_putstr_fd(ft_get_base_string(va_arg(args, int), 16), 1);
      else if (s[i + 1] == 'p')
      {
        char *p = va_arg(args, char *);
        char a = &p;
        ft_putstr_fd(a, 1);
      }
    }
    else
      ft_putchar_fd(s[i], 1);
    i++;
  }
  va_end(args);
  return 1;
}
