/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:12:33 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/17 02:10:06 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	print_has_taken_a_fork(t_philo *philo)
{
	if (philo->table->have_to_stop)
		return ;
	printf("%ld %d has taken a fork\n",
		get_current_time(philo->table->start_time), philo->n);
}

void	print_eat(t_philo *philo)
{
	if (philo->table->have_to_stop)
		return ;
	printf("%ld %d is eating\n",
		get_current_time(philo->table->start_time), philo->n);
}

void	print_sleep(t_philo *philo)
{
	if (philo->table->have_to_stop)
		return ;
	printf("%ld %d is sleeping\n",
		get_current_time(philo->table->start_time), philo->n);
}

void	print_think(t_philo *philo)
{
	if (philo->table->have_to_stop)
		return ;
	printf("%ld %d is thinking\n",
		get_current_time(philo->table->start_time), philo->n);
}

void	print_dead(t_philo *philo)
{
	philo->table->have_to_stop = DEAD;
	printf("%ld %d died\n",
		get_current_time(philo->table->start_time), philo->n);
}
