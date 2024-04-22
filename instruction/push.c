/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:15:14 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/22 16:31:12 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa_push(d_list *list_a, d_list *list_b)
{
	struct node *node_a;
	struct node *node_b;

	node_a = list_a->p_head;
	node_b = list_b->p_head;
	if (_b->p_head == NULL)
		return ;
	ft_lstadd_top(list_a, node_b->val);
	list_b->p_head = node_b->p_next;
	list_b->p_head->p_prev = NULL;
	free(node_b);
}			

void	pb_push(d_list *_a, d_list *_b)
{
	struct node *node_a;
	struct node *node_b;
	int			tmp;

	node_a = list_a->p_head;
	node_b = list_b->p_head;
	if (list_b->p_head == NULL)
		return ;
	ft_lstadd_top(list_b, node_a->val);
	list_a->p_head = node_a->p_next;
	list_a->p_head->p_prev = NULL;
	free(node_a);
}			
