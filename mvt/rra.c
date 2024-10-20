/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:40:56 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/18 15:40:58 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rra(t_tab *a)
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
    ft_printf("rra\n");
}