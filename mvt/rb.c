#include "push_swap.h"

void    rb(t_tab *b)
{
    int first;
    int i;

    if (!b || b->top < 1)
        return ;
    first = b->tab[0];
    i = 0;
    while (i < b->top)
    {
        b->tab[i] = b->tab[i + 1];
        i++;
    }
    b->tab[b->top] = first;
}