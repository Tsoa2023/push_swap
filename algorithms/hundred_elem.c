/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:26:16 by fharifen          #+#    #+#             */
/*   Updated: 2024/05/02 13:45:56 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// long	take_key(t_list **stack_a, int index)
// {
// 	struct node *node;
// 	long		key_nbr;

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

static void	top_key(t_list **stack_a, size_t size_a, int c, int pivot_len)
{
	struct node *node;
	int			index;
	int			prox;
	int			rra_move;
	size_t 		j;
	int			key_target;

	node = (*stack_a)->p_head;
	j = 0;
	key_target = (size_a / pivot_len) * (1 * c);
	prox = (*stack_a)->length / 2;
	while (j++ < (*stack_a)->length)
	{
		if (node->index < key_target)
		{
			index = node->index_lst;
			rra_move = (*stack_a)->length - index;
			if (prox >= index)
				while (index--)
					ra_rotate(stack_a, 1);
			else
				while (rra_move--)
					rra_rotate(stack_a, 1);
			return ;
		}
		node = node->p_next;
	}
}

void	pb_key(t_list **stack_a, t_list **stack_b, size_t size_a, int c, int pivot_len)
{
	size_t	i;

	i = 0;
	while (i++ < (size_a / pivot_len)) 
	{
		top_key(stack_a, size_a, c, pivot_len);
		pb_push(stack_a, stack_b, 1);
	}
}

void	sort_hundred(t_list **stack_a, t_list **stack_b)
{
	int		i;
	size_t	size_a;
	int		pivot_len;
	
	pivot_len = 4;
	if (is_sorted(stack_a))
		return ;
	size_a = (*stack_a)->length;
	i = 0;
	while (i++ < pivot_len + 1)
		pb_key(stack_a, stack_b, size_a, i, (pivot_len + 2));	
	sort1(stack_a, stack_b);	
	sort2(stack_a, stack_b);
}
