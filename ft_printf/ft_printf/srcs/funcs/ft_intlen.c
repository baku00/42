#include <stdio.h>

int	ft_intlen(long int nbr)
{
	unsigned long int	n;
	unsigned long int	nb;
	int			l;

	n = 1;
	l = 1;
	nb = nbr;
	if (nbr < 0)
	{
		nb = nbr * -1;
		l++;
	}
  else
    nb = nbr;
	if (nb < 10)
		return (l);
	while (n < nb)
	{
		n *= 10;
		l++;
	}
	if (n > nb)
	{
		n /= 10;
		l--;
	}
	return (l);
}
