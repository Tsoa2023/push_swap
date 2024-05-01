/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:08:05 by fharifen          #+#    #+#             */
/*   Updated: 2024/05/01 13:34:47 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

// void ft_print_lst(t_list **stack_a, t_list **stack_b)
// {
//     struct node *tmpa = (*stack_a)->p_head;
//     struct node *tmpb = (*stack_b)->p_head;
//     while (tmpa || tmpb)
//     {
//         if (tmpa)
//         {
//             printf("%d (%d) (%d)\t", tmpa->val, tmpa->index, tmpa->index_lst);
// 			fflush(stdout);
//             tmpa = tmpa->p_next;
//         }
// 		else
// 		{
// 			printf("-\t");
// 			fflush(stdout);
// 		}
//         if (tmpb)
//         {
//             printf("%d (%d) (%d)\t", tmpb->val, tmpb->index, tmpb->index_lst);
// 			fflush(stdout);
//             tmpb = tmpb->p_next;
//         }
// 		else
// 		{
// 			printf("-\t");
// 			fflush(stdout);
// 		}
//         printf("\n");
// 		fflush(stdout);
//     }
//     printf("_\t_\na\tb\n\n");
// 	fflush(stdout);
// }

// void check_sorted(t_list **stack)
// {
// 	if (is_sorted(stack))
// 		write(1, "Stack is sorted\n", 16);
// 	else 
// 		write(1, "Stack is not sorted\n", 20);
// }

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
	// ft_print_lst(stack_a, stack_b);
	if ((*stack_a)->length <= 3)
		three_elem(stack_a);
	if ((*stack_a)->length >= 4 && (*stack_a)->length <= 10)
		five_elem(stack_a, stack_b);
	// sort_hundred(stack_a, stack_b);

	// ft_print_lst(stack_a, stack_b);
	// check_sorted(stack_a);
    free_lst(stack_a);
    free_lst(stack_b);

    return (EXIT_SUCCESS);
}
