#include "push_swap.h"

void	push_initial_two(t_tab *a, t_tab *b)
{
	if (a->top == 3)
		pb(a, b);
	else
	{
		pb(a, b);
		pb(a, b);
	}
}

int	find_max(t_tab *a)
{
	int	i;
	int	j;

	i = a->tab[0];
	j = 0;
	while (j < a->top + 1)
	{
		if (a->tab[j] > i)
			i = a->tab[j];
		j++;
	}
	return (i);
}

void	sort_tree(t_tab *a)
{
	int	biggest_nbr;

	biggest_nbr = find_max(a);
	ft_printf("biggest_nbr = %d\n", biggest_nbr);
	if (a->tab[2] == biggest_nbr)
		ra(a);
	else if (a->tab[1] == biggest_nbr)
	{
		ft_printf("a->tab[1] = %d\n", a->tab[1]);
		rra(a);
	}
	if (a->tab[a->top] > a->tab[1])
    {
        ft_printf("a->tab[a->top] = %d | a->tab[a->top - 1] = %d\n", a->tab[a->top], a->tab[a->top - 1]);
		sa(a);
    }
}

void	rotate_or_push_a(t_tab *a, t_tab *b)
{
	int	x;

	x = a->median;
	ft_printf("a->top = %d | a->bottom = %d\n", a->tab[a->top], a->tab[0]);
	if (a->tab[a->top] > a->tab[0])
		ra(a);
	else
	{
		pb(a, b);
		ft_printf("b->tab[b->top] = %d | median = %d\n", b->tab[b->top], x);
		if (b->tab[b->top] >= x)
			rb(b);
	}
}

int	sort_in_tab_to_median(t_tab *a)
{
	int	median;
	int	*tab;

	int i, j;
	tab = malloc(sizeof(int) * a->size);
	i = 0;
	while (i < a->size)
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
	free(tab);
	return (median);
}
