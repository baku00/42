#include "../../../so_long.h"

int valid_close(char *filename)
{
  t_map map;
  int length;
  int first;

  map.fd = open(filename, O_RDONLY);
  map.line = "";
  map.width = 0;
  map.height = 0;
  first = 1;
  while (map.line) {
    map.line = get_next_line(map.fd);
    if (map.line)
      length = ft_strlen(map.line);
    else
      break;
    map.height++;
    if (first)
    {
      first = 0;
      map.width = length;
    }
    else if (map.width != length)
      error();
  }
  if (map.width == map.height)
    error();
  return (1);
}
