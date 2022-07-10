/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:17:22 by dgloriod          #+#    #+#             */
/*   Updated: 2022/07/10 19:16:44 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_philo_config	philo_config;
	int		i;

	if (argc != 5 && argc != 6)
	{
		ft_putendl_fd("Usage: ./philo <number of philos> <time to die> <time to eat> <time to sleep> [<number of eat>]", 1);
		return (0);
	}
	philo_config.number = ft_atoi(argv[1]);
	philos = ft_calloc(philo_config.number, sizeof(t_philo));
	if (!philos)
	{
		ft_putendl_fd("Memory error", 1);
		return (0);
	}
	philo_config.time_to_die = ft_atoi(argv[2]);
	if (!philo_config.time_to_die)
		return (0);	
	philo_config.time_to_eat = ft_atoi(argv[3]);
	philo_config.time_to_sleep = ft_atoi(argv[4]);
	i = -1;
	while (++i < philo_config.number)
	{
		
	}
	ft_putendl_fd("Config:", 1);
	ft_putnbr_fd(philo_config.time_to_die, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(philo_config.time_to_eat, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(philo_config.time_to_sleep, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
