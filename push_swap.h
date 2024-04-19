/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:59:44 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/19 11:40:44 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

struct node
{
    int val;
    struct node *p_next;
    struct node *p_prev;
};

typedef struct dlist
{
    unsigned int    length;
    struct node     *p_tail;
    struct node     *p_head;
}   d_list;

#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"


void    ft_lstadd_back(d_list *list, int data);
void    ft_lstadd_top(d_list *list, int data);
d_list  *ft_lst_new(void);

#endif
