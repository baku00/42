/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:12:41 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/17 02:39:23 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static int	have_the_time(t_philo *philo)
{
	return ((get_actual_time() - philo->last_eat) < philo->config.time_to_die);
}

static int	reach_number_of_eat(t_philo *philo)
{
	return (philo->number_of_eat >= philo->config.number_of_eat && \
	philo->config.number_of_eat >= 1);
}

int	have_to_stop(t_philo *philo)
{
	if (philo->table->have_to_stop)
		return (philo->table->have_to_stop);
	if (!have_the_time(philo))
		philo->table->have_to_stop = DEAD;
	else if (reach_number_of_eat(philo))
		philo->table->have_to_stop = REACH_MEAL;
	if (philo->table->have_to_stop && !philo->table->philo_stop)
		philo->table->philo_stop = philo->n;
	return (philo->table->have_to_stop);
}

void	supervisor(t_philo *philos)
{
	long int	time;

	time = 0;
	if (!philos->table->start_time)
		philos->table->start_time = get_actual_time();
	while (philos && philos->next && !philos->table->have_to_stop)
	{
		if (!have_to_stop(philos))
			philos = philos->next;
	}
	time = get_current_time(philos->table->start_time);
	if (philos->table->have_to_stop == DEAD)
		printf("%ld %d died\n", time, philos->table->philo_stop);
	else if (philos->table->have_to_stop == REACH_MEAL)
		printf("%ld %d has reach number of meal\n", time, \
		philos->table->philo_stop);
	remove_all(philos);
}
