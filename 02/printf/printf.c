#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int print_x(long int n)
{
	// printf("real: %lx\n", n);
	char c;
	int count = 0;
	long int quotient;
	long int reste;
	while (n > 0)
	{
		quotient = n / 16;
		reste = n - (quotient * 16);
		n /= 16;
		if (reste >= 10)
			c = reste + 55;
		else
			c = reste + 48;
		count += write(1, &c, 1);
	}
	return count;
}

int print_p(long int n)
{
	// printf("real: %ld\n", n);
	char c;
	int count = 0;
	long int min;
	long int quotient;
	long int reste;
	long int base;
	base = 16;
	min = 0;
	while (n > min)
	{
		quotient = n / base;
		reste = n - (quotient * base);
		n /= base;
		if (reste >= 10)
			c = reste + 55;
		else
			c = reste + 48;
		count += write(1, &c, 1);
	}
	return count;
}

int print_d(int n)
{
	printf("real: %d\n", n);
	int number[12];
	char c;
	int count = 0;
	int i = 0;
	long int in = n;
	if (in < 0)
	{
		count += write(1, "-", 1);
		if (in == -2147483648)
		{
			count += write(1, "2147483648", 11);
			return count;
		}
		in *= -1;
	}
	while (n > 0)
	{
		number[i] = n % 10;
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0) {
		c = number[i] + '0';
		count += write(1, &c, 1);
		i--;
	}
	return count;
}

int ft_printf(char *str, ...)
{
	va_list args;
	va_start(args, str);
	int i = 0;
	char c;
	int count = 0;
	while (str[i]) {
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'x')
				count += print_x(va_arg(args, int));
			else if (str[i] == 'd')
				count += print_d(va_arg(args, int));
			else if (str[i] == 'p')
			{
				count += write(1, "0x", 3);
				count += print_p(va_arg(args, long int));
			}
		}
		else
		{
			c = str[i];
			count += write(1, &c, 1);
		}
		i++;
	}
	return count;
}

int main()
{
	long int ptr = 127;
	int ft = ft_printf("%p\n", &ptr);
	int pr = printf("%p\n", &ptr);
	printf("%d == %d\n", ft, pr);
	return 0;
}
