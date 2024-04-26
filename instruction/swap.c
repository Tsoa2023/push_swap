/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:43:25 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/26 17:14:39 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa_swap(t_list **list, int flag)
{
	int	tmp;
	struct node	*node;

	node = (*list)->p_head;
	if ((*list)->p_head == NULL && (*list)->p_tail == NULL)
		return ;
	tmp = node->val;
	node->val = node->p_next->val;
	node->p_next->val = tmp;
	if (flag == 1)
		ft_putstr_fd("sa", 1);
}

void	sb_swap(t_list **list, int flag)
{
	int		tmp;
	struct node *node;

	node = (*list)->p_head;
	if ((*list)->p_head == NULL && (*list)->p_tail == NULL)
		return ;
	tmp = node->val;
	node->val = node->p_next->val;
	node->p_next->val = tmp;
	if (flag == 1)
		ft_putstr_fd("sb", 1);
}

void	ss_swap(t_list **list_a, t_list **list_b, int flag)
{
	sa_swap(list_a);
	sb_swap(list_b);
	if (flag == 1)
		ft_putstr_fd("ss", 1);
}
