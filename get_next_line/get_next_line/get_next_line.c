#include "get_next_line.h"

char  *get_next_line(int fd)
{
  int   i;
  int   ret;
  char  buf[2];
  char  *temp;
  char  *result;

  buf[1] = 0;
  result = NULL;
  i = 0;
  printf("Buffer: (%d)\n", BUFFER_SIZE);
  while ((ret = read(fd, buf, 1))) {
    printf("Ret: (%d)\n", ret);
    if (ret == -1)
      return (0);
    if (!result)
      result = "";
    temp = ft_strjoin(result, buf);
    result = ft_strdup(temp);
    free(temp);
    i++;
    if (buf[0] == '\n')
    {
      printf("======\nBreak\n=====\n");
      break;
    }
  }
  if (i == 0)
    return (0);
  return (result);
}
