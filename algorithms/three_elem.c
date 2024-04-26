/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:32:29 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/25 13:59:41 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	two_elem(d_list *stack)
{
	struct node *node;

	node = stack->p_head;
	if (stack->p_head == NULL && stack->p_tail == NULL)
		return ;
	while (node)
	{
		if ((node->index == 1 && node->p_next->index == 0) 
			|| (node->index == 0 && node->p_next->index == 2))
			sa_swap(stack);
		node = node->p_next;
	}
	if (node->index == 2 && node->p_next == 0 && node->p_next->p_next == 1)
		ra_rotate(stack);
	if (node->index == 1 && node->p_next == 2 && node->p_next->p_next == 0)
		
}
