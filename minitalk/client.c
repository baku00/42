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
	printf("1\n");
	static t_transmission	trans;

	printf("2\n");
	if (!trans.message)
	{
		printf("3\n");
		trans.message = ft_strdup(message);
		printf("4\n");
	}
	printf("5\n");
	if (!trans.pid)
	{
		printf("6\n");
		trans.pid = pid;
		printf("7\n");
	}
	printf("8\n");
	if (!trans.send_null)
	{
		printf("9\n");
		if (!trans.signals_temp || !trans.signals_temp[trans.j])
		{
			printf("10\n");
			if (trans.signals_temp && !trans.signals_temp[trans.j])
			{
				printf("11\n");
				(free(trans.signals_temp), trans.j = 0);
				printf("12\n");
				trans.signals_temp = 0;
				printf("13\n");
			}
			printf("14\n");
			if (!trans.message[trans.i])
			{
				printf("15\n");
				(free(trans.message), trans.send_null = 1);
				printf("16\n");
			}
			else
			{
				printf("17\n");
				(trans.signals_temp = i_t_b(trans.message[trans.i]), trans.i++);
				printf("18\n");
			}
			printf("19\n");
		}
		printf("20\n");
		if (trans.signals_temp)
		{
			printf("21\n");
			if (trans.signals_temp[trans.j] - 48)
			{
				printf("22\n");
				(kill(trans.pid, SIGUSR2), trans.j++);
				printf("23\n");
			}
			else
			{
				printf("24\n");
				(kill(trans.pid, SIGUSR1), trans.j++);
				printf("25\n");
			}
			printf("26\n");
		}
		printf("27\n");
	}
	if (!trans.signals_temp)
	{
		printf("28\n");
		send_null(trans.pid);
		printf("29\n");
	}
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

// printf("%ld\n", time(0));
