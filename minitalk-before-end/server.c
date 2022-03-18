#include <signal.h>
#include "minitalk.h"

void	handler(int signum)
{
	static t_transmission	transmission;
	static int count;

	if (!transmission.state)
	{
		transmission.state = 1;
		transmission.c[0] = 0;
		transmission.message = ft_calloc(1, sizeof(char));
	}

	// printf("128 >> %d => %d (%d)\n", transmission.state, 128 >> transmission.state, (signum - 10) / 2);
	count++;
	if ((signum - 10) / 2)
		transmission.c[0] += (128 >> transmission.state);
	transmission.state++;
	if (transmission.state == 8)
	{
		transmission.message = ft_strjoin(transmission.message, transmission.c);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nTemp message: %s\n", transmission.message);
		transmission.state = 1;
		if (!transmission.c[0])
		{
			printf("Message: %s\n", transmission.message);
			free(transmission.message);
			transmission.state = 0;
		}
		transmission.c[0] = 0;
	}
}

int main()
{
	ft_printf("PID Server: %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
