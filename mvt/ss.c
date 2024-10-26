/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:42:09 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/26 22:34:04 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_tab *a, t_tab *b)
{
	int	tmp_a;
	int	tmp_b;

	if (!a || a->top < 1 || !b || b->top < 1)
		return ;
	tmp_a = a->tab[a->top];
	a->tab[a->top] = a->tab[a->top - 1];
	a->tab[a->top - 1] = tmp_a;
	tmp_b = b->tab[b->top];
	b->tab[b->top] = b->tab[b->top - 1];
	b->tab[b->top - 1] = tmp_b;
	ft_printf("ss\n");
}
