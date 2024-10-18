#include "push_swap.h"

void    sb(t_tab *b)
{
    int tmp;

    if (!b || b->top < 1)
        return ;
    tmp = b->tab[b->top];
    b->tab[b->top] = b->tab[b->top - 1];
    b->tab[b->top - 1] = tmp;
}