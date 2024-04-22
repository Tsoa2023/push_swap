/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:13:32 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/22 16:28:39 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ra_rotate(d_list *list)
{
	struct node *node;

	node = list->p_head;
	ft_lstadd_back(list, node->val);
	list->p_head = node->p_next;
	list->p_head->prev = NULL;
	free(node);
}
