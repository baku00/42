#include "../../../client.h"

int	*atob(char *message)
{
	int		*result;
	int		i;
	int		j;
	int		state;
	size_t	length;
	char	c;

	length = ft_strlen(message);
	result = ft_calloc(length * 8 + 8, sizeof(int));
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (i <= length)
	{
		state = 64;
		c = message[i];
		while (state) {
			result[j] = c > state;
			if (result[j])
				c -= state;
			state /= 2;
			j++;
		}
		result[j] = c > state;
		if (result[j])
			c -= state;
		j++;
		i++;
	}
	return (result);
}
