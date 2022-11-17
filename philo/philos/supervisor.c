/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:41:29 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/17 02:11:37 by my_name_         ###   ########.fr       */
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
	if (!have_the_time(philo))
		philo->table->have_to_stop = DEAD;
	else if (reach_number_of_eat(philo))
		philo->table->have_to_stop = REACH_MEAL;
	return (philo->table->have_to_stop);
}

void	supervisor(t_philo *philo)
{
	while (philo->n != 1)
		philo = philo->next;
	while (1)
	{
		if (have_to_stop(philo))
		{
			philo_die(philo);
			break ;
		}
		else if (philo->table->have_to_stop == REACH_MEAL)
		{
			printf("Each philo eat [%d] time(s)\n",
				philo->config.number_of_eat);
			break ;
		}
		philo = philo->next;
	}
	remove_all(philo);
}
