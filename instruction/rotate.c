/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:13:32 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/22 21:40:14 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ra_rotate(d_list *list)
{
	struct node *node;

	node = list->p_head;
	ft_lstadd_back(list, node->val);
	list->p_head = node->p_next;
	list->p_head->p_prev = NULL;
	free(node);
	// ft_putstr_fd("ra\n", 1);
}

void	rb_rotate(d_list *list)
{
	struct node *node;

	node = list->p_head;
	ft_lstadd_back(list, node->val);
	list->p_head = node->p_next;
	list->p_head->p_prev = NULL;
	free(node);
	// ft_putstr_fd("rb\n", 1);
}

void	rr_rotate(d_list *list_a, d_list *list_b)
{
	ra_rotate(list_a);
	rb_rotate(list_b);
	// ft_putstr_fd("rr\n",1);
}