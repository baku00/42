#include "../../../client.h"

char	*btoa(int *binary, int length)
{
	char	*result;
	char	c;
	int		i;

	result = ft_calloc(length / 8, sizeof(char));
	i = 0;
	while (i < length)
	{
		c += binary[i++];
		printf("c %d\n", c);
		if (!(i % 8) && i)
			result[(i / 8) - 1] = c;
	}
	return (result);
}
