#include "minitalk.h"

int main(int argc, char **argv)
{
	t_transmission transmission;
	int count = 0;

	printf("128 >> 2 = %d\n", 128 >> 6);
	(void) argc;
	transmission.pid = ft_atoi(argv[1]);
	transmission.message = argv[2];
	transmission.i = 0;
	while (transmission.message[transmission.i++]) {
		transmission.j = 0;
		transmission.signals_temp = ft_itob(transmission.message[transmission.i - 1], 2, 0);
		transmission.length = ft_strlen(transmission.signals_temp);
		while (transmission.signals_temp[transmission.j] && transmission.length == 7) {
			printf("%c", transmission.signals_temp[transmission.j]);
			if (transmission.signals_temp[transmission.j] - 48)
				kill(transmission.pid, SIGUSR2);
			else
				kill(transmission.pid, SIGUSR1);
			count++;
			transmission.j++;
			usleep(350);
		}
		printf("\n");
	}
	transmission.i = 0;
	transmission.length = ft_strlen("0000000");
	while (transmission.i < transmission.length)
	{
		kill(transmission.pid, SIGUSR1);
		transmission.i++;
		usleep(350);
	}
	printf("Count: %d\n", count);
	for (int i = 1; i < 8; i++) {
		printf("128 >> %d => %d\n", i, 128 >> i);
	}
	return (0);
}
