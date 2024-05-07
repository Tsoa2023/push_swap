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

static void	top_key(t_list **stack_a, int size_a, int c, int pivot_len)
{
	int			ra_move;
	int			rra_move;
	int			key_target;

	key_target = (size_a / pivot_len) * (1 * c);
	ra_move = 0;
	rra_move = 0;
	if (under_pivot(stack_a, key_target, &ra_move, &rra_move))
	{
		while (ra_move--)
			ra_rotate(stack_a, 1);
	}
	else
		while (rra_move--)
				rra_rotate(stack_a, 1);
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
		top_key(stack_a, size_a, c, pivot_len);
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
	
	size_a = (*stack_a)->length;
	if (size_a % 5 == 0 || size_a % 10 == 0)
	{
		pivot_len = 4;
		if (is_sorted(stack_a))
			return ;
		i = 0;
		while (i++ < pivot_len + 1)
			pb_key(stack_a, stack_b, size_a, i, (pivot_len + 1));	
		sort2(stack_a, stack_b);
	}
	else
	{
		pivot_len = 5;
		if (is_sorted(stack_a))
			return ;
		i = 0;
		while (i++ < pivot_len + 2)
			pb_key(stack_a, stack_b, size_a, i, (pivot_len + 3));	
		sort1(stack_a, stack_b);	
		sort2(stack_a, stack_b);

	}	
}
