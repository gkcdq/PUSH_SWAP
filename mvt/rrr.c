/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:41:44 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/26 22:33:40 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rrra(t_tab *a)
{
	int	first;
	int	i;

	if (!a || a->top < 1)
		return ;
	first = a->tab[0];
	i = 0;
	while (i < a->top)
	{
		a->tab[i] = a->tab[i + 1];
		i++;
	}
	a->tab[a->top] = first;
}

static void	rrrb(t_tab *b)
{
	int	first;
	int	i;

	if (!b || b->top < 1)
		return ;
	first = b->tab[0];
	i = 0;
	while (i < b->top)
	{
		b->tab[i] = b->tab[i + 1];
		i++;
	}
	b->tab[b->top] = first;
}

void	rrr(t_tab *a, t_tab *b)
{
	rrra(a);
	rrrb(b);
	ft_printf("rrr\n");
}
