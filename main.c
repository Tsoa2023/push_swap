/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:08:05 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/19 11:50:21 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_lst(d_list *stack)
{
    struct node *tmp = stack->p_head;
    while (tmp)
    {
        printf("%d\n", tmp->val);
        tmp = tmp->p_next;
    }
    printf("_ _\na b\n");
}

void  init_stack(d_list *stack, char **argv, int argc)
{
  char **args;
  int   i;

  if (argc == 2)
    args = ft_split(argv[1], ' ');
  else 
  {
    args = argv;
    i = 1;
  }
  while (args[i])
  {
    ft_lstadd_back(stack, ft_atoi(args[i])); 
    i++;
  }
}

int main(int argc, char *argv[])
{
    d_list *stack_a;
    d_list *stack_b;
    
    if (argc < 2)
      return (0);
    stack_a = ft_lst_new();
    stack_b = ft_lst_new();

    init_stack(stack_a, argv, argc);
    ft_print_lst(stack_a);
    
    free(stack_a);
    free(stack_b);

    return (0);
}
