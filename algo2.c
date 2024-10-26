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

static int	find_cheapest_index_in_b(t_tab *b)
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

static int	find_target_index_in_a(t_tab *a, int cheapest)
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

static void	rotate_both(t_tab *a, t_tab *b)
{
	while (b->tab[b->top] != b->cheapest && a->tab[a->top] != a->target)
		rr(a, b);
}

static void	reverse_rotate_both(t_tab *a, t_tab *b)
{
	while (b->tab[b->top] != b->cheapest && a->tab[a->top] != a->target)
		rrr(a, b);
}

void	before_push_a(t_tab *a, int target_index)
{
	if (a->top < 0)
		return ;
	while (a->target != a->tab[a->top])
	{
		if (target_index < a->size_tab)
			rra(a);
		else if (target_index >= a->size_tab)
			ra(a);
	}
}

void	before_push_b(t_tab *b, int cheapest_index)
{
	if (b->top < 0)
		return ;
	while (b->cheapest != b->tab[b->top])
	{
		if (cheapest_index < b->size_tab)
			rrb(b);
		else if (cheapest_index >= b->size_tab)
			rb(b);
	}
}

void	calculate_size(t_tab *x)
{
	x->size_tab = x->top / 2;
}

void	turk_algorithm(t_tab *a, t_tab *b)
{
	int	cheapest_index;
	int	target_index;

	cheapest_index = find_cheapest_index_in_b(b);
	b->cheapest = b->tab[cheapest_index];
	target_index = find_target_index_in_a(a, b->cheapest);
	a->target = a->tab[target_index];
	if (cheapest_index >= b->size_tab && target_index >= a->size_tab)
		rotate_both(a, b);
	else if (cheapest_index < b->size_tab && target_index < a->size_tab)
		reverse_rotate_both(a, b);
	before_push_a(a, target_index);
	before_push_b(b, cheapest_index);
	pa(a, b);
	calculate_size(a);
	calculate_size(b);
}
