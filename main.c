/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:08:05 by fharifen          #+#    #+#             */
/*   Updated: 2024/05/05 20:44:51 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void  init_stack(t_list **stack, char **argv, int argc)
{
	char **args;
	int   i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ', &argc);
	else 
	{
		args = argv;
		i = 1;
	}
	while (args[i])
	{
		ft_lstadd_back(stack, ft_atoi(args[i])); 
		i++;
	}
	indexing(stack);
	init_index_lst(stack);
}

int main(int argc, char *argv[])
{
    t_list **stack_a;
    t_list **stack_b;
    
    stack_a = malloc(sizeof(t_list));
    stack_b = malloc(sizeof(t_list));
	init_lst(stack_a, stack_b);
    if (argc < 2 || check_error(argv, argc))
	{
		free_lst(stack_a);
		free_lst(stack_b);
        return (EXIT_FAILURE);
	}
    init_stack(stack_a, argv, argc);
	if ((*stack_a)->length <= 3)
		three_elem(stack_a);
	else if ((*stack_a)->length >= 4 && (*stack_a)->length <= 10)
		five_elem(stack_a, stack_b);
	else if ((*stack_a)->length > 10 && (*stack_a)->length <= 500)
		sort_hundred(stack_a, stack_b);
    free_lst(stack_a);
    free_lst(stack_b);
    return (EXIT_SUCCESS);
}
