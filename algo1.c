/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:31:09 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/26 22:31:11 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (a->tab[2] == biggest_nbr)
		ra(a);
	else if (a->tab[1] == biggest_nbr)
		rra(a);
	if (a->tab[a->top] > a->tab[1])
		sa(a);
}

void	rotate_or_push_a(t_tab *a, t_tab *b)
{
	int	x;

	x = a->median;
	if (!ft_check_tri(a) && a->tab[a->top] > a->tab[0])
		ra(a);
	else if (!ft_check_tri(a) && a->tab[a->top] < a->tab[0])
	{
		pb(a, b);
		if (b->tab[b->top] >= x)
			rb(b);
	}
}

int	sort_in_tab_to_median(t_tab *a)
{
	int	*tab;
	int	median;
	int	i;
	int	j;

	tab = malloc(sizeof(int) * a->size);
	copy_tab(a, tab);
	i = 0;
	while (i < a->size - 1)
	{
		j = 0;
		while (j < a->size - i - 1)
		{
			if (tab[j] < tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
	median = tab[a->size / 2];
	free(tab);
	return (median);
}

void	copy_tab(t_tab *a, int *tab)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		tab[i] = a->tab[i];
		i++;
	}
}
