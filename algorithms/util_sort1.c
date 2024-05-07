/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:16:29 by fharifen          #+#    #+#             */
/*   Updated: 2024/05/05 21:05:37 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	top_min(t_list **stack_a)
{
	struct node *node;
	int			index;
	int			prox;
	int			rra_move;

	node = (*stack_a)->p_head;
	while (node)
	{
		if (node->val == get_min(stack_a)->val)
		{
			index = node->index_lst;
			prox = (*stack_a)->length / 2;
			rra_move = (*stack_a)->length - index;
			if (prox >= index)
				while (index--)
					ra_rotate(stack_a, 1);
			else
				while (rra_move--)
					rra_rotate(stack_a, 1);
			return ;
		}
		node = node->p_next;
	}
}

void	sort1(t_list **stack_a, t_list **stack_b)
{
	size_t		i;
	size_t		size_a;

	size_a = (*stack_a)->length;
	if (is_sorted(stack_a))
		return ;
	i = 0;
	while (i++ < size_a - 3)
	{
		top_min(stack_a);
		pb_push(stack_a, stack_b, 1);
	}
	three_elem(stack_a);
	i = 0;
	while (i++ < size_a - 3)
		pa_push(stack_a, stack_b, 1);
}

static struct node	*min_move(t_list **stack_b, int *do_rb, int *do_rrb)
{
	struct node *node_top;
	struct node *node_tail;

	node_top = (*stack_b)->p_head;
	node_tail = (*stack_b)->p_tail;
	while (node_top)
	{
		if (node_top == get_max(stack_b))
		{
			*do_rb = node_top->index_lst;
			break ;
		}
		node_top = node_top->p_next;		
	}
	while (node_tail)
	{
		if (node_tail == get_max(stack_b))
		{
			*do_rrb = (*stack_b)->length - node_tail->index_lst;
			break ;
		}
		node_tail = node_tail->p_prev;		
	}
	if (*do_rb <= *do_rrb)
		return (node_top);
	return (node_tail);
}

static void	top_max_1(t_list **stack_a, t_list **stack_b, int *flag)
{
	struct node *node_b;
	int			rb_move;
	int			rrb_move;

	rb_move = 0;
	rrb_move = 0;
		node_b = min_move(stack_b, &rb_move, &rrb_move);
		if (rb_move <= rrb_move)
		{
			while (rb_move--)
			{
				rb_rotate(stack_b, 1);
				if ((*stack_b)->p_head->index == node_b->index - 1)
				{
					pa_push(stack_a, stack_b, 1);
					*flag = 1;
					rb_move--;
				}
			}
		}
		else
			while (rrb_move--)
			{
				rrb_rotate(stack_b, 1);
				if ((*stack_b)->p_head->index == node_b->index + 1)
				{
					pa_push(stack_a, stack_b, 1);
					*flag = 1;
					rrb_move--;
				}
			}
}

void	sort2(t_list **stack_a, t_list **stack_b)
{
	size_t		i;
	size_t		size_b;
	int			flag;

	size_b = (*stack_b)->length;
	if ((*stack_b)->p_head == NULL)
		return ;
	i = 0;
	while (i++ < size_b)
	{
		flag = 0;
		top_max_1(stack_a, stack_b, &flag);
		pa_push(stack_a, stack_b, 1);
		if (flag == 1)
			sa_swap(stack_a, 1);
	}
}
