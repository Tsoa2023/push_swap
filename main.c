/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:07:05 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/18 21:30:02 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void ft_print_lst(d_list *stack)
{
    struct node *tmp = stack->p_head;
    while (tmp)
    {
        printf("%d\n", tmp->val);
        tmp = tmp->p_next;
    }
}

int main(int argc, char *argv[])
{
    d_list *stack_a;
    
    stack_a = ft_lst_new();

    ft_lstadd_back(stack_a, 5);
    ft_lstadd_back(stack_a, 1);
    ft_print_lst(stack_a);

    free(stack_a);

    return (0);
}