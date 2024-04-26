/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:35:12 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/26 08:27:24 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static struct node *min(t_list **stack) 
{
	struct node *node;
	struct node	*min;

	node = (*stack)->p_head;
	min = NULL;
	while (node)
	{
		if (node->index == -1 && (min == NULL || node->val < min->val))
			min = node;
		node = node->p_next;
	}
	return (min);
}

void	init_index(t_list **stack)
{
	struct node *node;

	node = (*stack)->p_head;
	while (node)
	{
		node->index = -1;
		node = node->p_next;
	}
}

void	indexing(t_list **stack)
{
	size_t		i;
	struct node *node;

	i = 0;
	init_index(stack);
	while (i < (*stack)->length)
	{
		node = min(stack);
		node->index = i++;
	}
}

struct node *get_min(t_list **stack)
{
	struct node *node;
	struct node *min;

	node = (*stack)->p_head;
	min = NULL;
	while (node)
	{
		if (min == NULL || node->val < min->val)
			min = node;
		node = node->p_next;
	}
	return (min);
}

struct node *get_max(t_list **stack)
{
	struct node *node;
	struct node *max;

	node = (*stack)->p_head;
	max = NULL;
	while (node)
	{
		if (max == NULL || node->val > max->val)
			max = node;
		node = node->p_next;
	}
	return (max);
}
