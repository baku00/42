/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:21:00 by dgloriod          #+#    #+#             */
/*   Updated: 2022/07/10 16:14:44 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "srcs/libft/libft.h"
# include "headers/includes.h"

typedef struct s_philo_config
{
    int number;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_eat;
}   t_philo_config;

typedef struct s_philo
{
    pthread_t   thread;
}   t_philo;

int	main(int argc, char **argv);

#endif
