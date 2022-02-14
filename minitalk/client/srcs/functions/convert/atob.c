#include "../../../client.h"

typedef struct s_convert
{
	size_t	len;
	size_t	index;
	int		c;
	int		state;
}	t_convert;

int	*atob(char *message)
{
	int			*result;
	t_convert	convert;
	char		c;

	convert.len = ft_strlen(message);
	result = ft_calloc(convert.len * 8 + 8, sizeof(int));
	if (!result)
		return (0);
	convert.index = -1;
	convert.c = 0;
	while (++convert.index <= convert.len)
	{
		convert.state = 128;
		c = message[convert.index];
		while (convert.state)
		{
			result[convert.c] = c >= convert.state;
			if (result[convert.c])
				c -= convert.state;
			convert.state /= 2;
			convert.c++;
		}
	}
	return (result);
}
