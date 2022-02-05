#include "../../so_long.h"

void	ft_exit(char *message, int error)
{
	if (error)
		printf("\033[31;01mErreur: \033[00m");
	printf("%s\n", message);
	exit(0);
}
