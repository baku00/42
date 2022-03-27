#include "minitalk.h"

static char	*i_t_b(int c)
{
	t_int_to_binary	itb;

	itb.i = 0;
	itb.from = 128;
	itb.can_convert = 0;
	itb.result = ft_calloc(9, sizeof(char));
	if (!itb.result)
		return (0);
	while (itb.i < 8)
	{
		itb.move_bytes = itb.from >> itb.i;
		itb.can_convert = c >= itb.move_bytes;
		itb.result[itb.i] = itb.can_convert + 48;
		if (itb.can_convert)
			c -= itb.move_bytes;
		itb.i++;
	}
	return (itb.result);
}

static void	send_null(int pid)
{
	static int	i;

	if (i < 8)
		kill(pid, SIGUSR1);
	else
		exit(0);
	i++;
}

static void	send_messages(char *message, int pid)
{
	static t_transmission	trans;

	if (!trans.message)
		trans.message = ft_strdup(message);
	if (!trans.pid)
		trans.pid = pid;
	if (!trans.send_null)
	{
		if (!trans.signals_temp || !trans.signals_temp[trans.j])
		{
			if (trans.signals_temp && !trans.signals_temp[trans.j])
			{
				(free(trans.signals_temp), trans.j = 0);
				trans.signals_temp = 0;
			}
			if (!trans.message[trans.i])
				(free(trans.message), trans.send_null = 1);
			else
				(trans.signals_temp = i_t_b(trans.message[trans.i]), trans.i++);
		}
		if (trans.signals_temp)
		{
			if (trans.signals_temp[trans.j] - 48)
				(kill(trans.pid, SIGUSR2), trans.j++);
			else
				(kill(trans.pid, SIGUSR1), trans.j++);
		}
	}
	if (!trans.signals_temp)
		send_null(trans.pid);
}

void	handler(int signum)
{
	(void) signum;
	if (signum == SIGUSR2)
		send_messages(0, 0);
	else
		(ft_putstr_fd("Fin de la transmission\n", 1), exit(0));
}

int	main(int argc, char **argv)
{
	t_transmission	transmission;

	(void) argc;
	transmission.pid = ft_atoi(argv[1]);
	transmission.message = argv[2];
	send_messages(transmission.message, transmission.pid);
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
		pause();
}

// rintf("%ld\n", time(0));
