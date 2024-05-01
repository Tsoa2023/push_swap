/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:16:29 by fharifen          #+#    #+#             */
/*   Updated: 2024/05/01 11:50:46by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	top_min(t_list **stack_a)
{
	struct node *node;
	int			index;
	int			prox;
	int			rra_move;

	node = (*stack_a)->p_head;
	while (node)
	{
		if (node->val == get_min(stack_a)->val)
		{
			index = node->index_lst;
			prox = (*stack_a)->length / 2;
			rra_move = (*stack_a)->length - index;
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

void	sort1(t_list **stack_a, t_list **stack_b)
{
	size_t		i;
	size_t		size_a;

	size_a = (*stack_a)->length;
	if (is_sorted(stack_a))
		return ;
	i = 0;
	while (i++ < size_a - 3)
	{
		top_min(stack_a);
		pb_push(stack_a, stack_b, 1);
	}
	three_elem(stack_a);
	i = 0;
	while (i++ < size_a - 3)
		pa_push(stack_a, stack_b, 1);
}

// sort b to a
static void	top_max(t_list **stack_a, t_list **stack_b)
{
	struct node *node;
	int			index;
	int			i;

	node = (*stack_b)->p_head;
	while (node)
	{
		if (node->val == get_max(stack_b)->val)
		{
			index = node->index_lst;
			i = 0;
			if (get_max(stack_b)->index_lst == 1)
				sb_swap(stack_b, 1);
			if (get_max(stack_b)->index_lst == 0)
			{
				pa_push(stack_a, stack_b, 1);	
				return ;
			}	
			else
				while (i++ < index)
					rb_rotate(stack_b, 1);
			pa_push(stack_a, stack_b, 1);
			while (--i)
				rrb_rotate(stack_b, 1);
		}
		node = node->p_next;
	}
}

void	sort2(t_list **stack_a, t_list **stack_b)
{
	size_t		i;
	size_t		size_b;

	size_b = (*stack_b)->length;
	if ((*stack_b)->p_head == NULL)
		return ;
	i = 0;
	while (i++ < size_b)
		top_max(stack_a, stack_b);
}