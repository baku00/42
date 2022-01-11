#include "../../client.h"

void	ft_send_transmition(t_transmition *transmition)
{
	int	i;

	i = 0;
	printf("\nSending...\n");
	while (i < transmition->length)
	{
		ft_printf("%d", transmition->signals[i++]);
		if (!(i % 8))
			ft_printf("\n");
	}
	printf("BTOA: %s\n", btoa(transmition->signals, transmition->length));
}
