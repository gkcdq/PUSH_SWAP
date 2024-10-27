/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:20:18 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/27 19:20:19 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_size(t_tab *x)
{
	x->size_tab = x->top / 2;
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

void	algorithm(t_tab *a, t_tab *b)
{
	int	cheapest_index;
	int	target_index;

	cheapest_index = find_cheapest_index_in_b(b);
	b->cheapest = b->tab[cheapest_index];
	target_index = find_target_index_in_a(a, b->cheapest);
	a->target = a->tab[target_index];
	if (cheapest_index >= b->size_tab && target_index > a->size_tab)
		rotate_both(a, b);
	else if (cheapest_index < b->size_tab && target_index <= a->size_tab)
		reverse_rotate_both(a, b);
	before_push_a(a, target_index);
	before_push_b(b, cheapest_index);
	pa(a, b);
	calculate_size(a);
	calculate_size(b);
}
