/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:14:37 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/18 21:27:12 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// Allocate a new list
d_list  *ft_lst_new(void)
{
    d_list *new;

    new = (d_list*)malloc(sizeof(d_list));
    if (new != NULL)
    {
     new->length = 0;
     new->p_head = NULL;               
     new->p_tail = NULL;               
    }
    return (new);
}

// Add list in back 
void ft_lstadd_back(d_list *list, int data)
{
    if (list == NULL)
        return ;

    struct node *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL)
        return ;

    new_node->val = data;
    new_node->p_next = NULL;

    if (list->p_tail == NULL)
    {
        new_node->p_prev = NULL;
        list->p_tail = new_node;
        list->p_head = new_node;
    }
    else
    {
        list->p_tail->p_next = new_node;
        new_node->p_prev = list->p_tail;
        list->p_tail = new_node;
    }

    list->length++;
}
