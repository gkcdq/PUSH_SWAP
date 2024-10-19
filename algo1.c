#include "../push_swap.h"

void    rotate_or_push_a(t_tab *a, t_tab *b)
{
    if (!a || a->top < 1)
        return ;
    if (a->tab[a->top] > a->tab[0])
        ra(a);
    else if (a->tab[a->top] < a->tab[0])
        pb(a, b);
}


