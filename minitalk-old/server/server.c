#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "./includes/ft_printf/ft_printf.h"

char	ft_btoa(char *binary)
{
	int	i;
	int c;
	int state = 64;

	i = 0;
	c = 0;
	while (i < ft_strlen(binary))
	{
		if (binary[i] == '1')
			c += state;
		state /= 2;
		i++;
	}
	return c;
}

char	*join(char *str, char c, int length)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = ft_calloc(length + 1, sizeof(char));
	while (i < length) {
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	return (new_str);
}

void my_handler(int signum)
{
	static int i;
	static char	*bytes;
	static char	*cbytes;
	static char	last_bytes[7];
	int			j;
	int			is_null;

	j = 0;
	if (!i)
	{
		bytes = ft_calloc(1, sizeof(char));
		cbytes = ft_calloc(1, sizeof(char));
		if (!bytes || !cbytes)
			return ;
	}
	bytes = join(bytes, (signum - 10) / 2, i);
	cbytes = join(cbytes, (signum - 10) / 2 + 48, i);
	last_bytes[i % 7] = (signum - 10) / 2;
	if (i % 7 == 0)
	{
		j = 0;
		is_null = 1;
		while (j < 8)
		{
			if (last_bytes[j])
				is_null = 0;
			last_bytes[j] = 0;
			j++;
		}
		printf("is_null: %d\n", is_null);
		if (is_null)
		{
			j = 0;
			printf("%zu\n", ft_strlen(cbytes));
			while (j < ft_strlen(cbytes))
			{
				char *substr = ft_substr(cbytes, j, j + 7);
				printf("substr: %s\n", substr);
				char btoa = ft_btoa(substr);
				printf("%c => J: %d\n", btoa, j);
				j += 7;
			}
			printf("\n");
			free(bytes);
			free(cbytes);
			i = 0;
		}
	}
	i++;
}

int main(void)
{
	pid_t process_id;
	// pid_t p_process_id;
	process_id = getpid();
	printf("Server running on The process id: %d\n",process_id);
	while (1) {
		// p_process_id = getppid();

		// printf("The process id of parent function: %d\n",p_process_id);
		signal(SIGUSR1, my_handler);
		signal(SIGUSR2, my_handler);
		sleep(0.0000001);
	}
	return 0;
}
