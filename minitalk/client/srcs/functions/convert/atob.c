#include "../../../client.h"

int	*atob(char *message)
{
	int		*result;
	size_t	size_ts[3];
	char	c;

	size_ts[2] = ft_strlen(message);
	result = ft_calloc(size_ts[2] * 8 + 8, sizeof(int));
	if (!result)
		return (0);
	size_ts[0] = -1;
	size_ts[1] = 0;
	while (++size_ts[0] <= size_ts[2])
	{
		state = 128;
		c = message[size_ts[0]];
		while (state)
		{
			result[size_ts[1]] = c >= state;
			if (result[size_ts[1]])
				c -= state;
			state /= 2;
			size_ts[1]++;
		}
	}
	return (result);
}
