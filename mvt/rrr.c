/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:41:44 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/18 15:41:45 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void    rrra(t_tab *a)
{
    int last;
    int i = 0;

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

static void    rrrb(t_tab *b)
{
    int last;
    int i;

    if (!b || (b->top == -1))
        return ;
    last = b->tab[b->top];
    i = b->top;
    while (i > 0)
    {
        b->tab[i] = b->tab[i - 1];
        i--;
    }
    b->tab[b->top] = last;
}

void    rrr(t_tab *a, t_tab *b)
{
    rrra(a);
    rrrb(b);
    ft_printf("rrr\n");
}
