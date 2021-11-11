#include "get_next_line.h"
#include <malloc/malloc.h>

char  *get_next_line(int fd)
{
	int   i;
	int   ret;
	char  buf[2];
	char  *temp;
	char  *result;

	buf[1] = '\0';
	result = NULL;
	temp = NULL;
	i = 0;
	while ((ret = read(fd, buf, 1))) {
		if (ret == -1)
		{
			if (result)
				free(result);
			return (0);
		}
		if (!result)
			result = "";
		temp = ft_strjoin(result, buf);
		result = ft_strdup(temp);
		free(temp);
		i++;
		if (buf[0] == '\n')
			break;
	}
	if (i == 0)
		return (0);
	return (result);
}
