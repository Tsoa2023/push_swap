/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:50:36 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/29 10:01:08 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Allocate a new list
t_list  *ft_lst_new(void)
{
    t_list *new;

    new = (t_list*)malloc(sizeof(t_list));
    if (new != NULL)
    {
		new->length = 0;
		new->p_head = NULL;               
		new->p_tail = NULL;
    }
    return (new);
}

void	init_lst(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL)
        EXIT_FAILURE ;
	if (stack_b == NULL)
        EXIT_FAILURE ;
    *stack_a = ft_lst_new();
    *stack_b = ft_lst_new();
}

// Add list to back 
void ft_lstadd_back(t_list **list, int data)
{
    if ((*list) == NULL)
        return ;

    struct node *new_node;
    new_node = malloc(sizeof(*new_node));
    if (new_node == NULL)
        return ;
    new_node->val = data;
	new_node->index = -1;
    new_node->p_next = NULL;
    if ((*list)->p_tail == NULL)
    {
        new_node->p_prev = NULL;
        (*list)->p_tail = new_node;
        (*list)->p_head = new_node;
    }
    else
    {
        (*list)->p_tail->p_next = new_node;
        new_node->p_prev = (*list)->p_tail;
        (*list)->p_tail = new_node;
    }
    (*list)->length++;
}

// Add list to top
void ft_lstadd_top(t_list **list, int data)
{
	struct node *new_node;
	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return ;
	new_node->val = data;
	new_node->index = -1;
	new_node->p_prev = NULL;
	if ((*list)->p_head == NULL)
	{
		new_node->p_next = NULL;
		(*list)->p_tail = new_node;
		(*list)->p_head = new_node;
	}
	else	
	{
		new_node->p_next = (*list)->p_head;
		(*list)->p_head->p_prev = new_node;
		(*list)->p_head = new_node;
	}
	(*list)->length++;
}
 
void	free_lst(t_list **list)
{
	struct node *tmp;
	struct node *del;

	del = (*list)->p_head;
	if ((*list) != NULL)
	{
		while (del)
		{
			tmp = del->p_next;
			free(del);
			del = tmp;
		}
		free(*list), *list = NULL;
		free(list);
	}
}

void	init_index_lst(t_list **list)
{
	struct node *node;
	int			i;
	
	node = (*list)->p_head;
	if ((*list)->p_head == NULL)
		return ;
	i = 0;
	while (node)
	{
		node->index_lst = i++;
		node = node->p_next;
	}
}
