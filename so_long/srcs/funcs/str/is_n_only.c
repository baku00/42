#include "../../../so_long.h"

int is_n_only(const char *str, const char c, const int length)
{
  int i;

  i = 0;
  while (str[i] && i < length)
  {
    if (str[i] != c)
      return 0;
    i++;
  }
  return 1;
}
