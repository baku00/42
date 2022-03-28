#include "minitalk.h"

void	handler(int signum)
{
	(void) signum;
	if (signum == SIGUSR2)
		send_message(0, 0);
	else
		(ft_putstr_fd("Fin de la transmission\n", 1), exit(0));
}

int	main(int argc, char **argv)
{
	t_transmission	transmission;

	(void) argc;
	transmission.pid = ft_atoi(argv[1]);
	transmission.message = argv[2];
	send_message(transmission.message, transmission.pid);
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
		pause();
}
