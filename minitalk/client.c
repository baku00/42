#include "minitalk.h"

static char	*int_to_binary(int c)
{
	int		i = 0;
	int		from = 128;
	int		move_bytes;
	int		can_convert = 0;
	char	*result;

	result = ft_calloc(9, sizeof(char));

	result[8] = 0;
	while (i < 8) {
		move_bytes = from >> i;
		can_convert = c >= move_bytes;
		result[i] = can_convert + 48;
		if (can_convert)
			c -= move_bytes;
		i++;
	}
	return result;
}

static void	send_null(int pid)
{
	static int	i;

	if (i < 8)
		kill(pid, SIGUSR1);
	else
		return ;
	i++;
}

static void	send_messages(char *message, int pid)
{
	static t_transmission transmission;

	if (!transmission.message)
		transmission.message = ft_strdup(message);
	if (!transmission.pid)
		transmission.pid = pid;
	if (!transmission.i)
		transmission.i = 0;
	if (!transmission.j)
		transmission.j = 0;
	if (!transmission.signals_temp || !transmission.signals_temp[transmission.j])
	{
		if (!transmission.message || !transmission.message[transmission.i])
		{
			if (transmission.message)
			{
				free(transmission.message);
				transmission.message = NULL;
			}
			send_null(transmission.pid);
		}
		transmission.signals_temp = int_to_binary(transmission.message[transmission.i]);
		printf("Signal temp: %s => %d => %c\n", transmission.signals_temp, transmission.message[transmission.i], transmission.message[transmission.i]);
		transmission.i++;
		transmission.j = 0;
	}
	if (transmission.signals_temp[transmission.j])
	{
		if (transmission.signals_temp[transmission.j] - 48)
			kill(transmission.pid, SIGUSR2);
		else
			kill(transmission.pid, SIGUSR1);
		transmission.j++;
	}
}

void	handler(int signum)
{
	(void) signum;
	if (signum == SIGUSR2)
		send_messages(0, 0);
	else
	{
		ft_putstr_fd("Fin de la transmission\n", 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_transmission transmission;

	(void) argc;
	transmission.pid = ft_atoi(argv[1]);
	transmission.message = argv[2];
	send_messages(transmission.message, transmission.pid);
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
		pause();
}
