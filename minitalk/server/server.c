#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "./includes/ft_printf/ft_printf.h"

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
	is_null = 1;
	if (!i)
	{
		bytes = ft_calloc(1, sizeof(char));
		cbytes = ft_calloc(1, sizeof(char));
		if (!bytes || !cbytes)
			return ;
	}
	bytes = join(bytes, (signum - 10) / 2, i);
	cbytes = join(cbytes, (signum - 10) / 2 + 48, i);
	printf("%s\n", cbytes);
	last_bytes[i % 7] = (signum - 10) / 2;
	if (i % 7 == 0)
	{
		while (j < 7)
		{
			if (last_bytes[j])
				is_null = 0;
			last_bytes[j] = 0;
			j++;
		}
		last_bytes[7] = 0;
		if (is_null)
			printf("%s", bytes);
	}
	i++;
}

int main(void)
{
	pid_t process_id;
	// pid_t p_process_id;
	process_id = getpid();
	printf("The process id: %d\n",process_id);
	while (1) {
		// p_process_id = getppid();

		// printf("The process id of parent function: %d\n",p_process_id);
		signal(SIGUSR1, my_handler);
		signal(SIGUSR2, my_handler);
		sleep(0.0000001);
	}
	return 0;
}
