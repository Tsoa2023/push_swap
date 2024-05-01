/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:38:51 by fharifen          #+#    #+#             */
/*   Updated: 2024/05/01 13:42:47 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_sorted(t_list **stack)
{
	struct node *node;

	node = (*stack)->p_head;
	if (node == NULL && node == NULL)
		return (1);
	while (node->p_next)
	{
		if (node->val > node->p_next->val)
			return (0);
		node = node->p_next;
	}
	return (1);
}

int	is_double(char **argv, int size, int i)
{
	int	j;

	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(ft_atoi(argv[i]), ft_atoi(argv[j])) == 0)
				return (1);
			j++;
		}	
		i++;
	}
	return (0);
}

int	outside_int(char **argv, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	not_digit(char **argv, int size, int i)
{
	int		j;

	while (i < size)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
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
		args = ft_split(argv[1], ' ', &argc);
	else
		args = argv + 1;
	if (not_digit(args, argc - 1, i) || is_double(args, argc - 1, i) 
		|| outside_int(args, argc - 1))
	{
		ft_putstr_fd("Error\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}