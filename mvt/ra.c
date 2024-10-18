#include "push_swap.h"

void    ra(t_tab *a)
{
    int first;
    int i;

    if (!a || a->top < 1)
        return ;
    first = a->tab[0];
    i = 0;
    while (i < a->top)
    {
        a->tab[i] = a->tab[i + 1];
        i++;
    }
    a->tab[a->top] = first;
}