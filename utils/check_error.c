/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:38:51 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/22 23:14:41 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_double(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}	
		i++;
	}
	return (0);
}

int check_error(char **argv, int argc)
{
	char **args;
	int		i;
	
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else 
	{
		args = argv;
		i = 1;
	}
		
	while (args[i])
	{
		if (!ft_isdigit(*args[i]) || is_double(args, argc))
		{
			ft_putstr_fd("Error\n", 1);
			return (EXIT_FAILURE);
		}
		i++;	
	}
	return (EXIT_SUCCESS);
}
