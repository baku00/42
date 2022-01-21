#include "../../../client.h"

char	*btoa(int *binary, int length)
{
	char	*result;
	int		i;
	int		state;
	char	c;

	i = 0;
	result = ft_calloc(length / 8, sizeof(char));
	state = 128;
	c = 0;
	if(!result)
		return (0);
	while (i < length) {
		if (binary[i])
			c += state;
		state /= 2;
		if (!(i % 8) && i)
		{
			result[(i / 8) - 1] = c;
			state = 64;
			c = 0;
		}
		i++;
	}
	return (result);
}
