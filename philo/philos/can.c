/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:12:23 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/17 01:47:11 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	can_take_a_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (fork == NULL)
		return (0);
	if (pthread_mutex_lock(fork) == 0)
	{
		if (!have_to_stop(philo))
		{
			print_has_taken_a_fork(philo);
		}
		return (1);
	}
	return (0);
}

int	can_eat(t_philo *philo)
{
	return (philo->number_of_eat < philo->config.number_of_eat);
}
