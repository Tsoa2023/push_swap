/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:59:44 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/26 17:14:51 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

struct node
{
    int			val;
	int			index;
    struct node *p_next;
    struct node *p_prev;
}; 
  
typedef struct list  
{  
    size_t		length;  
    struct node *p_tail;   
    struct node *p_head;
}   t_list;      
       
void    ft_lstadd_back(t_list **list, int data, int flag);  
void    ft_lstadd_top(t_list **list, int data);   
t_list  *ft_lst_new(void);
void	init_lst(t_list **stack_a, t_list **stack_b);
void	free_lst(t_list **list);
void	sa_swap(t_list **list, int flag);     
void	sb_swap(t_list **list, int flag);      
void	ss_swap(t_list **list_a, t_list **list_b, int flag);
void	push(t_list *list, struct node *elem);
void	push_back(t_list *list, struct node *elem);     
void	pa_push(t_list **list_a, t_list **list_b, int flag); 
void	pb_push(t_list **list_a, t_list **list_b, int flag);  
int     check(char **argv, int argc);
void    ra_rotate(t_list **list, int flag);  
void	rb_rotate(t_list **list, int flag);  
void	rr_rotate(t_list **list_a, t_list **list_b, int flag);
void	rra_rotate(t_list **list, int flag); 
void	rrb_rotate(t_list **list, int flag); 
void	rrr_rotate(t_list **list_a, t_list **list_b, int flag);
int     check_error(char **argv, int argc);
int		is_sorted(t_list **stack);
void	indexing(t_list **stack);
struct node *get_min(t_list **stack);
struct node *get_max(t_list **stack);

#endif
