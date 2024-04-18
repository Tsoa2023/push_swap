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


void    ft_lstadd_back(d_list *list, int data);
d_list  *ft_lst_new(void);

#endif