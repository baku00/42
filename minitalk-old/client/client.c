#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "./includes/ft_printf/ft_printf.h"

int main(int argc, char **argv)
{
	(void) argc;
	pid_t	pid;
	char	*message;
	char	end[8];
	char	send[8];
	char	*char_to_send;
	int		i;
	int		j;

	i = 0;
	pid = atoi(argv[1]);
	message = argv[2];
	send[7] = 0;
	while (i <= ft_strlen(message)) {
		char_to_send = ft_itob(message[i], 2, 0);
		j = 0;
		while (char_to_send[j])
		{
			if (char_to_send[j] == 48)
				kill(pid, SIGUSR1);
			else if (char_to_send[j] == 49)
				kill(pid, SIGUSR2);
			j++;
			sleep(0.0000001);
		}
		printf("%s\n", char_to_send);
		i++;
	}
	printf("\n");
	return 0;
}
//
//
//
// int main(int argc, char **argv)
// {
// 	printf("%s\n", ft_itob(783492, 2, 0));
// 	return 0;
// }
