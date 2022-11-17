/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:12:26 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/17 02:39:23 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static void	update_meal(t_philo *philo)
{
	if (philo->config.number_of_eat >= 1)
	{
		philo->number_of_eat += 1;
		if (philo->number_of_eat >= philo->config.number_of_eat)
		{
			philo->table->have_to_stop = REACH_MEAL;
			philo->table->philo_stop = philo->n;
		}
	}
}

void	make_eat(t_philo *philo)
{
	t_philo	*next;

	if (!philo)
		return ;
	next = philo->next;
	if (can_take_a_fork(philo) == 0 && can_eat(philo) && !have_to_stop(philo))
	{
		print_has_taken_a_fork(philo);
		if (can_take_a_fork(next) == 0 && !have_to_stop(philo))
		{
			print_has_taken_a_fork(philo);
			print_eat(philo);
			milliseconde_sleep(philo->config.time_to_eat);
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(&next->fork);
			update_meal(philo);
			philo->last_eat = get_actual_time();
			philo->state = SLEEPING_STATE;
		}
		if (have_to_stop(philo))
			pthread_mutex_unlock(&philo->fork);
	}
}

void	make_sleep(t_philo *philo)
{
	if (!philo || have_to_stop(philo))
		return ;
	print_sleep(philo);
	milliseconde_sleep(philo->config.time_to_sleep);
	philo->state = THINKING_STATE;
}

void	make_think(t_philo *philo)
{
	if (!philo || have_to_stop(philo))
		return ;
	print_think(philo);
	philo->state = WAIT_FOR_EAT_STATE;
}

void	make_start(t_philo *philo)
{
	if (!philo || have_to_stop(philo))
		return ;
	milliseconde_sleep(philo->config.time_to_eat / 2);
	philo->state = WAIT_FOR_EAT_STATE;
}
