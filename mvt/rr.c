/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:41:19 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/26 22:33:33 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotatea(t_tab *a)
{
	int	last;
	int	i;

	if (!a || a->top < 1)
		return ;
	last = a->tab[a->top];
	i = a->top;
	while (i > 0)
	{
		a->tab[i] = a->tab[i - 1];
		i--;
	}
	a->tab[0] = last;
}

static void	rotateb(t_tab *b)
{
	int	last;
	int	i;

	if (!b || (b->top < 1))
		return ;
	last = b->tab[b->top];
	i = b->top;
	while (i > 0)
	{
		b->tab[i] = b->tab[i - 1];
		i--;
	}
	b->tab[0] = last;
}

void	rr(t_tab *a, t_tab *b)
{
	rotatea(a);
	rotateb(b);
	ft_printf("rr\n");
}
