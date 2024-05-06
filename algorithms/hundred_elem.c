/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:26:16 by fharifen          #+#    #+#             */
/*   Updated: 2024/05/05 21:13:02 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// long	take_key(t_list **stack_a, int index)
// {
// 	struct node *node;
// 	long		key_nbr;

// 	node = (*stack_a)->p_head;
// 	if ((*stack_a)->p_head == NULL)
// 		return (0);
// 	while (node)
// 	{
// 		if (node->index == index)
// 			key_nbr = node->val;
// 		node = node->p_next;
// 	}
// 	return (key_nbr);
// }


// void	correct_spot(t_list **stack_a, t_list **stack_b)
// {
//
// }

int	under_pivot(t_list **stack_a, int key_target, int *do_ra, int *do_rra)
{
	struct node *node_top;
	struct node *node_tail;

	node_top = (*stack_a)->p_head;
	node_tail = (*stack_a)->p_tail;
	while (node_top)
	{
		if (node_top->index < key_target)
		{
			*do_ra = node_top->index_lst;
			break ;
		}
		node_top = node_top->p_next;		
	}
	while (node_tail)
	{
		if (node_tail->index < key_target)
		{
			*do_rra = (*stack_a)->length - node_tail->index_lst;
			break ;
		}
		node_tail = node_tail->p_prev;		
	}
	if (*do_ra <= *do_rra)
		return (1);
	return (0);
}

static void	top_key(t_list **stack_a,/*  t_list **stack_b, */ int size_a, int c, int pivot_len)
{
	// struct node *node;
	int			ra_move;
	int			rra_move;
	size_t 		j;
	int			key_target;

	j = 0;
	key_target = (size_a / pivot_len) * (1 * c);
	ra_move = 0;
	rra_move = 0;
	while (j++ < (*stack_a)->length)
	{
		if (under_pivot(stack_a, key_target, &ra_move, &rra_move) == 1)
		{
			while (ra_move--)
			{
				// if (ra_move < 1)
				// 	rr_rotate(stack_a, stack_b, 1);
				// else
					ra_rotate(stack_a, 1);

			}
		}
		else
			while (rra_move--)
			{
				// if (ra_move < 1)
				// 	rrr_rotate(stack_a, stack_b, 1);
				// else
					rra_rotate(stack_a, 1);
			}
		return ;
	}
}

void	pb_key(t_list **stack_a, t_list **stack_b, int size_a, int c, int pivot_len)
{
	int	i;
	int tmp;
	static int med;
	struct node *ptr;

	if (med == 0)
		med = (size_a / pivot_len) / 2;
	tmp = (size_a / pivot_len);
	i = 0;
	while (i++ < (size_a / pivot_len)) 
	{
		top_key(stack_a, /* stack_b, */ size_a, c, pivot_len);
		pb_push(stack_a, stack_b, 1);
		ptr = (*stack_b)->p_head;
		if (ptr->index < med)
			rb_rotate(stack_b, 1);
	}
	med += tmp; 

}

void	sort_hundred(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int	size_a;
	int		pivot_len;
	
	pivot_len = 4;
	if (is_sorted(stack_a))
		return ;
	size_a = (*stack_a)->length;
	i = 0;
	while (i++ < pivot_len + 1) /* pivot_len + 2 et + 3*/
		pb_key(stack_a, stack_b, size_a, i, (pivot_len));	
	// sort1(stack_a, stack_b);	
	sort2(stack_a, stack_b);
}
