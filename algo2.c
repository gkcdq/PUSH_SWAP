/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:31:21 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/26 22:31:22 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest_index_in_b(t_tab *b)
{
	int	cheapest_index;
	int	cheapest_value;
	int	i;

	cheapest_index = -1;
	cheapest_value = INT_MAX;
	i = 0;
	while (i <= b->top)
	{
		if (b->tab[i] < cheapest_value)
		{
			cheapest_value = b->tab[i];
			cheapest_index = i;
		}
		i++;
	}
	return (cheapest_index);
}

int	find_target_index_in_a(t_tab *a, int cheapest)
{
	int	i;

	i = a->top;
	while (i >= 0)
	{
		if (a->tab[i] > cheapest)
			return (i);
		i--;
	}
	return (0);
}

void	rotate_both(t_tab *a, t_tab *b)
{
	while (b->tab[b->top] != b->cheapest && a->tab[a->top] != a->target)
		rr(a, b);
}

void	reverse_rotate_both(t_tab *a, t_tab *b)
{
	while (b->tab[b->top] != b->cheapest && a->tab[a->top] != a->target)
		rrr(a, b);
}
