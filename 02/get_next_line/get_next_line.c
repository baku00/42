#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

size_t ft_strlen(char *str)
{
	size_t i = -1;
	while (str[++i]);
	return i;
}

char *strjoin(char *s1, char *s2)
{
	if (!s1 || !s2)
		return 0;
	size_t ls1 = ft_strlen(s1), ls2 = ft_strlen(s2);
	char *str = malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!str)
		return 0;
	str[ls1 + ls2] = 0;
	int i = 0, j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	free(s1);
	return str;
}

char *get_next_line(int fd)
{
	int ret = 1;
	char buff[2];
	char *result = malloc(1 * sizeof(char));
	if (!result)
		return 0;
	result[0] = 0;
	buff[1] = 0;
	while ((ret = read(fd, buff, 1)))
	{
		result = strjoin(result, buff);
		if (buff[0] == '\n' || !buff[0])
			break;
	}
	return result;
}

int main()
{
	int fd = open("./test.txt", O_RDONLY);
	char *line;
	while (ft_strlen(line = get_next_line(fd)) > 0)
		printf("%s", line);
	return 0;
}
