#include "../../client.h"

void	ft_init_transmition(t_transmition *transmition, char **argv)
{
	transmition->pid = ft_atoi(argv[1]);
	transmition->message = argv[2];
	transmition->length = ft_strlen(transmition->message) * 8 + 8;
	transmition->signals = atob(transmition->message);
}
