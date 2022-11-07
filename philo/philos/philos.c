/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:51:58 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/07 23:00:25 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philos.h"



static t_config	create_config(int argc, char **argv)
{
	t_config	config;

	config.number_of_philos = ft_atoi(argv[1]);
	config.time_to_die = ft_atoi(argv[2]);
	config.time_to_eat = ft_atoi(argv[3]);
	config.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		config.number_of_eat = ft_atoi(argv[5]);
	else
		config.number_of_eat = -1;
	return (config);
}

static t_philo	*configure_philo(t_philo *philo, t_config config)
{
	int	i;

	i = -1;
	while (++i < config.number_of_philos)
	{
		philo[i].n = i + 1;
		philo[i].last_eat = 0;
		philo[i].number_of_eat = 0;
		philo[i].config = config;
		philo[i].fork_number = 0;
		pthread_mutex_init(philo[i].fork, NULL);
	}
	return (philo);
}

static t_philo *create_philos(t_config config)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), config.number_of_philos);
	if (!philo)
		return (NULL);
	return (philo);
}

static t_philo	*create_thread(t_philo *philo)
{
	int	i;

	i = -1;
	while (philo[++i])
		philo[i].thread_id = \
		pthread_create(philo[i].thread, NULL, routine, philo);
}

t_philo	*init_philos(int argc, char **argv)
{
	t_philo		*philo;
	t_config	config;

	config = create_config(argc, argv);
	philo = create_philos(config);
	philo = configure_philo(philo, config);
	philo = create_thread(philo);
}