/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:21:00 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/07 22:51:37 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "config.h"
# include "headers/includes.h"

typedef struct s_config
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_eat;
}	t_config;

typedef struct s_philo
{
	int				n;
	int				last_eat;
	int				number_of_eat;
	t_config		config;
	int				thread_id;
	int				fork_number;
	pthread_mutex_t	*fork;
	pthread_t		*thread;
}   t_philo;

int	main(int argc, char **argv);

#endif
