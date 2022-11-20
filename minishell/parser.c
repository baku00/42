/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: my_name_ <my_name_@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:00:20 by my_name_          #+#    #+#             */
/*   Updated: 2022/11/18 17:58:07 by my_name_         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
# define APOSTROPHE 39
# define GUILLEMET 34
# define PIPE '|'

int	find_next(char *args, int i, char c)
{
	int	next;

	next = i;
	while (args[next] != c)
		next++;
	return (next);
}

void	parser(char *argv)
{
	int		i;
	int		start;
	int		next;
	int		substr;
	char	c;
	(void) start;
	(void) next;
	

	i = -1;
	start = 0;
	while (argv[++i])
	{
		if (argv[i] == GUILLEMET || argv[i] == APOSTROPHE)
		{
			c = argv[i];
			i += 1;
			next = find_next(argv, i, c);
			substr = next - i;
			printf("Substr(%s, %d, %d): (%s)\n\n", argv, i, substr, ft_substr(argv, i, substr));
			i = next;
		}
	}
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	parser("'1\"1'   \"Hello ''\"  '22'   '\"Comment ça va ?\"'     '33'    ");
	return (0);
}
