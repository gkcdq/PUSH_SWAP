#include "push_swap.h"

void    rrb(t_tab *b)
{
    int last;
    int i;

    if (!b || (b->top == -1))
        return ;
    last = b->tab[b->top];
    i = b->top;
    while (i > 0)
    {
        b->tab[i] = b->tab[i - 1];
        i--;
    }
    b->tab[b->top] = last;
}