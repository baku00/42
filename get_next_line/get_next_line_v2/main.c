#include "get_next_line.h"

int main()
{
  int fd = open("42", O_RDONLY);
  if (fd == -1)
  {
    printf("Failed\n");
  }
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  close(fd);
  return (0);
}
