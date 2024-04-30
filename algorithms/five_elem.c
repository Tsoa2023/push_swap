/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:32:52 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/30 16:22:19 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


static void	top_min(t_list **stack_a, int i)
{
	struct node *node;
	int			index;
	int			prox;
	int			rra_move;

	node = (*stack_a)->p_head;
	while (node)
	{
		if (node->index == i)
		{
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
}

void	five_elem(t_list **stack_a, t_list **stack_b)
{
	size_t		i;
	size_t		size_a;

	size_a = (*stack_a)->length;
	if (is_sorted(stack_a))
		return ;
	i = 0;
	while (i < size_a - 3)
	{
		top_min(stack_a, i++);
		pb_push(stack_a, stack_b, 1);
	}
	three_elem(stack_a);
	i = 0;
	while (i++ < size_a - 3)
		pa_push(stack_a, stack_b, 1);
}
