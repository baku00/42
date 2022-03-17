#include "client.h"

int	main(int argc, char **argv)
{
	t_transmition	transmition;

	if (argc != 3)
		ft_exit(INVALID_SYNTAXE);
	ft_init_transmition(&transmition, argv);
	ft_send_transmition(&transmition);
	return (0);
}
