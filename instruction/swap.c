/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:43:25 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/29 10:30:09 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sa_swap(t_list **list, int flag)
{
    struct node *first;
    struct node *second;

    if ((*list)->p_head == NULL || (*list)->p_head->p_next == NULL)
        return;
    first = (*list)->p_head;
    second = first->p_next;
    first->p_next = second->p_next;
    if (second->p_next != NULL)
        second->p_next->p_prev = first;
    first->p_prev = second;
    second->p_next = first;
    second->p_prev = NULL;
    (*list)->p_head = second;
	init_index_lst(list);
    if (flag == 1)
        ft_putstr_fd("sa\n", 1);
}

void sb_swap(t_list **list, int flag)
{
    struct node *first;
    struct node *second;

    if ((*list)->p_head == NULL || (*list)->p_head->p_next == NULL)
        return;
    first = (*list)->p_head;
    second = first->p_next;
    first->p_next = second->p_next;
    if (second->p_next != NULL)
        second->p_next->p_prev = first;
    first->p_prev = second;
    second->p_next = first;
    second->p_prev = NULL;
    (*list)->p_head = second;
	init_index_lst(list);
    if (flag == 1)
        ft_putstr_fd("sb\n", 1);
}

void	ss_swap(t_list **list_a, t_list **list_b, int flag)
{
	sa_swap(list_a, 0);
	sb_swap(list_b, 0);
	if (flag == 1)
		ft_putstr_fd("ss\n", 1);
}
