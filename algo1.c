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
    int x = a->median;
    if (!a || a->top < 1)
        return ;
    if (a->tab[0] < a->tab[a->top])
        ra(a);
    else if (a->tab[0] > a->tab[a->top])
    {
        pb(a, b);
        if (b->tab[b->top] >= x)
            rrb(b);
    }
}

int sort_in_tab_to_median(t_tab *a) 
{
    int i, j;
    int median;
    int *tab;

    tab = malloc(sizeof(int) * a->size);
    i = 0;
    while(i < a->size)
    {
        tab[i] = a->tab[i];
        i++;
    }
    i = 0;
    while (i < a->size - 1)
    {
        j = 0;
        while (j < a->size - i - 1) 
        {
            if (tab[j] > tab[j + 1]) 
                ft_swap(&tab[j], &tab[j + 1]);
            j++;
        }
        i++;
    }
    median = tab[a->size / 2];
    return (median);
}
