#include "../../../server.h"

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
		state = 128;
		c = message[i];
		while (state) {
			result[j] = c >= state;
			if (result[j])
				c -= state;
			state /= 2;
			j++;
		}
		i++;
	}
	return (result);
}
