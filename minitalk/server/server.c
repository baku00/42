#include "server.h"

static void	print_message(t_transmition *transmition)
{
	ft_printf("Message: %s\n\n", transmition->message);
	free(transmition->message);
	transmition->message = NULL;
}

static void	check_state(t_transmition *transmition)
{
	if (!transmition->state)
	{
		transmition->message = ft_strjoin(transmition->message, transmition->c);
		if (!transmition->c[0])
			print_message(transmition);
	}
}

void	my_handler(int signum)
{
	static t_transmition	transmition;

	transmition.c[1] = 0;
	if (!transmition.message)
	{
		transmition.message = ft_calloc(1, sizeof(char));
		if (!transmition.message)
			return ;
	}
	if (!transmition.state)
	{
		transmition.state = 128;
		transmition.c[0] = 0;
	}
	if (signum == SIGUSR2)
		transmition.c[0] += transmition.state;
	transmition.state /= 2;
	check_state(&transmition);
}

int	main(void)
{
	t_transmition	transmition;

	ft_printf("PID Server: %d\n", getpid());
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1)
		pause();
	return (0);
}
