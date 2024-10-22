#include "push_swap.h"

void push_initial_two(t_tab *a, t_tab *b)
{
    if (a->top == 3)
        pb(a, b);
    else
    {
        pb(a, b);
        pb(a, b);
    }
}

int     find_max(t_tab *a)
{
    int i = a->tab[0];
    int j = 0;
    while (j < a->top)
    {
        if (a->tab[j] > i)
            i = a->tab[j];
        j++;
    }
    return (i);
}

void sort_tree(t_tab *a)
{
    int biggest_nbr = find_max(a);
    if (a->tab[0] == biggest_nbr)
        ra(a);                    
    else if (a->tab[1] == biggest_nbr) 
        rra(a);
    if (a->tab[0] > a->tab[1])
        sa(a);                                
}

void    rotate_or_push_a(t_tab *a, t_tab *b)
{
    if (!a || a->top < 1)
        return ;
    if (a->tab[a->top] > a->tab[0])
        rra(a);
    else if (a->tab[a->top] < a->tab[0])
        pb(a, b);
    if (a->top == 2)
        sort_tree(a);
}