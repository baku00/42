/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:31:43 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/17 02:15:29 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	philo_eat(t_philo *philo)
{
	t_philo	*next;

	next = philo->next;
	if (can_take_a_fork(philo, &philo->fork) && \
	can_take_a_fork(philo, &next->fork))
	{
		if (!have_to_stop(philo))
		{
			philo->state = EATING_STATE;
			print_eat(philo);
			philo->last_eat = get_actual_time();
			if (philo->config.number_of_eat > 0)
				philo->number_of_eat += 1;
			milliseconde_sleep(philo->config.time_to_eat);
		}
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&next->fork);
}

void	philo_sleep(t_philo *philo)
{
	if (!have_to_stop(philo))
	{
		philo->state = SLEEPING_STATE;
		print_sleep(philo);
		milliseconde_sleep(philo->config.time_to_sleep);
	}
}

void	philo_die(t_philo *philo)
{
	philo->table->have_to_stop = DEAD;
	print_dead(philo);
}

void	philo_think(t_philo *philo)
{
	if (!have_to_stop(philo))
	{
		philo->state = THINKING_STATE;
		print_think(philo);
	}
}
