#include "../../server.h"

void	ft_init_transmition(t_transmition *transmition, char **argv)
{
	transmition->pid = ft_atoi(argv[1]);
	transmition->message = argv[2];
	transmition->length = ft_strlen(transmition->message) * 8 + 8;
	transmition->signals = atob(transmition->message);
	printf("PID: %d\n", transmition->pid);
	printf("Message: %s\n", transmition->message);
	printf("Length: %zu\n", transmition->length);
	printf("Signals:\n");
	for (size_t i = 0; i < transmition->length; i++) {
		printf("%d", transmition->signals[i]);
		if (!(i % 8) && i)
			printf("\n");
	}
}
