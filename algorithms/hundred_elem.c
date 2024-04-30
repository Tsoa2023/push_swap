/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:26:16 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/30 17:27:04 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// long	take_key(t_list **stack_a, int index)
// {
// 	struct node *node;
// 	long		key_nbr;
//
// 	node = (*stack_a)->p_head;
// 	if ((*stack_a)->p_head == NULL)
// 		return (0);
// 	while (node)
// 	{
// 		if (node->index == index)
// 			key_nbr = node->val;
// 		node = node->p_next;
// 	}
// 	return (key_nbr);
// }
//
//
// static void	key_top(t_list **stack_a)
// {
// 	struct node *node;
// 	int			index;
// 	int			prox;
// 	int			rra_move;
//
// 	node = (*stack_a)->p_head;
// 	while (node)
// 	{
// 		if (node->index <= 25)
// 		{
// 			index = node->index_lst;
// 			prox = (*stack_a)->length / 2;
// 			rra_move = (*stack_a)->length - index;
// 			printf("index = %d   prox = %d   rra_move = %d\n", index, prox, rra_move);
// 			if (prox >= index)
// 				while (index--)
// 					ra_rotate(stack_a, 1);
// 			else
// 				while (rra_move--)
// 					rra_rotate(stack_a, 1);
// 		}
// 		node = node->p_next;
// 	}
// }

static void	top_min(t_list **stack_a, int i)
{
	struct node *node;
	int			index;
	int			prox;
	int			rra_move;

	node = (*stack_a)->p_head;
	int j = 0;
	while (j++ < 100)
	{
		if (node->index < 25)
		{
			printf("node->index = %d\n", node->index);
			index = node->index_lst;
			prox = (*stack_a)->length / 2;
			rra_move = (*stack_a)->length - index;
			printf("index = %d   prox = %d   rra_move = %d\n", index, prox, rra_move);
			if (prox >= index)
				while (index--)
					ra_rotate(stack_a, 1);
			else
				while (rra_move--)
					rra_rotate(stack_a, 1);
		}
		node = node->p_next;
	}
	printf("i = %d\n", i);
}

void	sort_hundred(t_list **stack_a, t_list **stack_b)
{
	size_t	i;
	size_t	size_a;

	size_a = (*stack_a)->length;
	if (is_sorted(stack_a))
		return ;
	i = 0;
	while (i < (size_a / 4)) 
	{
		top_min(stack_a, i++);
		pb_push(stack_a, stack_b, 1);
	}

}
