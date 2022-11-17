/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:28:35 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/17 02:10:28 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	if (philo->state == WAIT_FOR_START)
		milliseconde_sleep(philo->config.time_to_eat / 2);
	while (1)
	{
		if (!have_to_stop(philo))
		{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
		else
			break ;
	}
	return (NULL);
}
