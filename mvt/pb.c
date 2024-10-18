#include "push_swap.h"

void    pb(t_tab *a, t_tab *b)
{
    int x_a;

    if (!a || !b || (a->top == -1))
        return ;
    x_a = a->tab[a->top];
    if (b->top + 1 >= b->size)
        return ;
    b->top++;
    b->tab[b->top] = x_a;
    a->top--;
}