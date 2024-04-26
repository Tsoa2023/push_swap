/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:15:14 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/26 16:57:55 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	push(t_list *list, struct node *elem)
{
	elem->p_next = list->p_head;
	if (list->p_head != NULL)
		list->p_head->p_prev = elem;
	else
		list->p_tail = elem;
	list->p_head = elem;
	elem->p_prev = NULL;
	list->length++;
}

void	push_back(t_list *list, struct node *elem)
{
	elem->p_prev = list->p_tail;
	if (list->p_head != NULL)
		list->p_tail->p_next = elem;
	else
		list->p_head = elem;
	list->p_tail = elem;
	elem->p_next = NULL;
	list->length++;
}

void	pa_push(t_list **list_a, t_list **list_b, int flag)
{
	struct node *node_b;

	node_b = (*list_b)->p_head;
	if ((*list_b)->p_head == NULL)
		return ;
	(*list_b)->p_head = node_b->p_next;
	if ((*list_b)->p_head != NULL)
		(*list_b)->p_head->p_prev = NULL;
	push(*list_a, node_b);
	if (flag == 1)
		ft_putstr_fd("pa", 1);
}			

void	pb_push(t_list **list_a, t_list **list_b, int flag)
{
	struct node *node_a;

	node_a = (*list_a)->p_head;
	if ((*list_a)->p_head == NULL)
		return ;
	(*list_a)->p_head = node_a->p_next;
	if ((*list_a)->p_head != NULL)
		(*list_a)->p_head->p_prev = NULL;
	push(*list_b, node_a);
	if (flag == 1)
		ft_putstr_fd("pb", 1);
}			
