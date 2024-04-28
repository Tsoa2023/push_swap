/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:32:29 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/28 21:05:22by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void three_elem(t_list **stack_a)
{
    struct node *node;
	 
	node = (*stack_a)->p_head;
	if (node == NULL || is_sorted(stack_a))
		return ;
	if (node->p_next->index == 0)
	{
		if ((*stack_a)->p_head->val < (*stack_a)->p_tail->val)
	 		sa_swap(stack_a, 1);
		else
			ra_rotate(stack_a, 1);	
	}
	else if (node->p_next->p_next->index == 0)
	{
		if ((*stack_a)->p_head->val > (*stack_a)->p_head->p_next->val)
		{
	 		sa_swap(stack_a, 1);
			rra_rotate(stack_a, 1);
		}
		else
			rra_rotate(stack_a, 1);
	}	
	else
	{
		sa_swap(stack_a, 1);
		ra_rotate(stack_a, 1);	
	}
}
