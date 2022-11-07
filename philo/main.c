/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgloriod <dgloriod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:17:22 by dgloriod          #+#    #+#             */
/*   Updated: 2022/11/07 23:00:32 by dgloriod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static int	usage()
{
	printf("Usage:\n");
	printf("Number of philosophers\n");
	printf("Time to die\n");
	printf("Time to eat\n");
	printf("Time to sleep\n");
	printf("Number of times each philosophers must eat\n");
	printf("TIPS: Time to die > time to eat + time to sleep + 10 => Stay in life\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*philos;

	if (!check_arguments(argc, argv))
		return (usage());
	philos = init_philos();
	return (0);
}

/*
2 Philo
410 time to die
200			eat
200			sleep
5			number eat

-> think 
*/
