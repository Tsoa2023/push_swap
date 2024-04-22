/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:43:25 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/22 21:39:58 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa_swap(d_list *list)
{
	int	tmp;
	struct node	*node;

	node = list->p_head;
	if (list->p_head == NULL && list->p_tail == NULL)
		return ;
	tmp = node->val;
	node->val = node->p_next->val;
	node->p_next->val = tmp;
	// ft_putstr_fd("sa", 1);
}

void	sb_swap(d_list *list)
{
	int		tmp;
	struct node *node;

	node = list->p_head;
	if (list->p_head == NULL && list->p_tail == NULL)
		return ;
	tmp = node->val;
	node->val = node->p_next->val;
	node->p_next->val = tmp;
	// ft_putstr_fd("sb", 1);
}

void	ss_swap(d_list *list_a, d_list *list_b)
{
	sa_swap(list_a);
	sb_swap(list_b);
	// ft_putstr_fd("ss", 1);
}
