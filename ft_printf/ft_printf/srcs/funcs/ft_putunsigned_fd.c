#include "../../ft_printf.h"
#include <unistd.h>

void	ft_putunsigned_fd(unsigned long long int nb, int fd)
{
	char	nbr[20];
	int		i;

	i = 0;
	if (nb == 0)
		write(fd, "0", 1);
	while (nb != 0)
	{
		nbr[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	while (--i >= 0)
		write(fd, &nbr[i], 1);
}
