/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:13:32 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/29 10:30:38 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ra_rotate(t_list **list, int flag)
{
	struct node *node;

	node = (*list)->p_head;
	if (node == NULL)
		return ;
	(*list)->p_head = node->p_next;
	(*list)->p_head->p_prev = NULL;
	push_back(*list, node);
	init_index_lst(list);
	if (flag == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rb_rotate(t_list **list, int flag)
{
	struct node *node;

	node = (*list)->p_head;
	if (node == NULL || node->p_next == NULL)
		return ;
	(*list)->p_head = node->p_next;
	(*list)->p_head->p_prev = NULL;
	push_back(*list, node);
	init_index_lst(list);
	if (flag == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rr_rotate(t_list **list_a, t_list **list_b, int flag)
{
	ra_rotate(list_a, 0);
	rb_rotate(list_b, 0);
	if (flag == 1)
		ft_putstr_fd("rr\n",1);
}

void rra_rotate(t_list **list, int flag)
{
    struct node *node;

    node = (*list)->p_tail;
    if (node == NULL || node->p_prev == NULL)
        return ;
    (*list)->p_tail = node->p_prev;
    node->p_prev->p_next = NULL;
    node->p_next = (*list)->p_head;
    node->p_prev = NULL;
    (*list)->p_head->p_prev = node;
    (*list)->p_head = node;
	init_index_lst(list);
    if (flag == 1)
        ft_putstr_fd("rra\n", 1);
}

void rrb_rotate(t_list **list, int flag)
{
    struct node *node;

    node = (*list)->p_tail;
    if (node == NULL || node->p_prev == NULL)
        return ;
    (*list)->p_tail = node->p_prev;
    node->p_prev->p_next = NULL;
    node->p_prev = NULL;
    node->p_next = (*list)->p_head;
    (*list)->p_head->p_prev = node;
    (*list)->p_head = node;
	init_index_lst(list);
    if (flag == 1)
        ft_putstr_fd("rrb\n", 1);
}

void rrr_rotate(t_list **list_a, t_list **list_b, int flag)
{
	rra_rotate(list_a, 0);
	rrb_rotate(list_b, 0);
	if (flag == 1)
		ft_putstr_fd("rrr\n", 1);
}
