#include "push_swap.h"

void    rra(t_tab *a)
{
    int last;
    int i = 0;

    if (!a || a->top < 1)
        return ;
    last = a->tab[a->top];
    i = a->top;
    while (i > 0)
    {
        a->tab[i] = a->tab[i - 1];
        i--;
    }
    a->tab[0] = last;
}