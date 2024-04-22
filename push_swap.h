/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:59:44 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/22 16:32:13 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

struct node
{
    int val;
    struct node *p_next;
    struct node *p_prev;
};

typedef struct dlist
{
    size_t    length;
    struct node     *p_tail;
    struct node     *p_head;
}   d_list;

void    ft_lstadd_back(d_list *list, int data);
void    ft_lstadd_top(d_list *list, int data);
d_list  *ft_lst_new(void);
void	sa_swap(d_list *list);
void	sb_swap(d_list *list);
void	ss_swap(d_list *list_a, d_list *list_b);
void	pa_push(d_list *list_a, d_list *list_b);
int check(char **argv, int argc);

#endif
