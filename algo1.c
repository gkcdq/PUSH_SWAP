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

void	sort_tree(t_tab *a)
{
	int	biggest_nbr;

	biggest_nbr = find_max(a);
	if (!ft_check_tri(a) && biggest_nbr == a->tab[0])
		ra(a);
	else if (!ft_check_tri(a) && (a)->tab[1] > biggest_nbr)
		rra(a);
	if (!ft_check_tri(a) && (a)->tab[a->top] < (a)->tab[a->top - 1])
		sa(a);
}

void push_back_to_a(t_tab *a, t_tab *b)
{
    while (b->top >= 0)
    {
        pa(b, a);
    }
}

void bring_min_to_top(t_tab *a)
{
    int min_index = find_min(a);
    if (min_index <= a->top / 2)
    {
        while (min_index > 0)
        {
            ra(a);
            min_index--;
        }
    }
    else
    {
        while (min_index <= a->top)
        {
            rra(a);
            min_index++;
        }
    }
}

int find_min(t_tab *a)
{
    int min_value = a->tab[0];
    int min_index = 0;
    int i;

    for (i = 1; i <= a->top; i++)
    {
        if (a->tab[i] < min_value)
        {
            min_value = a->tab[i];
            min_index = i;
        }
    }
    return min_index;
}
void    rotate_or_push_a(t_tab *a, t_tab *b)
{
    if (!a || a->top < 1)
        return ;
    if (a->tab[a->top] > a->tab[0])
        ra(a);
    else if (a->tab[a->top] < a->tab[0])
        pb(a, b);
}