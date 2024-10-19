#include "push_swap.h"

void    free_t_tab(t_tab *a, t_tab *b)
{
        if (a)
        {
            free(a->tab);
            free(a);
        }
        if (b)
        {
            free(b);
        }
        return ;
}