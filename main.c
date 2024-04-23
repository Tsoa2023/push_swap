/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharifen <fiononana.hari@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:08:05 by fharifen          #+#    #+#             */
/*   Updated: 2024/04/23 16:20:33 by fharifen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void ft_print_lst(d_list *stack_a, d_list *stack_b)
{
    struct node *tmpa = stack_a->p_head;
    struct node *tmpb = stack_b->p_head;
    while (tmpa || tmpb)
    {
        if (tmpa)
        {
            printf("%d\t", tmpa->val);
            tmpa = tmpa->p_next;
        }
        if (tmpb)
        {
            printf("%d", tmpb->val);
            tmpb = tmpb->p_next;
        }
        printf("\n");
    }
    printf("_\t_\na\tb\n\n");
}

void  init_stack(d_list *stack, char **argv, int argc)
{
  char **args;
  int   i;

  i = 0;
  if (argc == 2)
      args = ft_split(argv[1], ' ', &argc);
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
    
    if (argc < 2 || check_error(argv, argc))
        return (EXIT_FAILURE);
    stack_a = ft_lst_new();
    stack_b = ft_lst_new();

    
    init_stack(stack_a, argv, argc);
    init_stack(stack_b, argv, argc);
    rr_rotate(stack_a, stack_b);
    ft_print_lst(stack_a, stack_b);

    free(stack_a);
    free(stack_b);

    return (EXIT_SUCCESS);
}
