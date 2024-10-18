/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:40:33 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/18 15:40:34 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pb(t_tab *a, t_tab *b)
{
    int x_a;

    if (!a || !b || (a->top == -1))
        return ;
    x_a = a->tab[a->top];
    b->top++;
    b->tab[b->top] = x_a;
    a->top--;
    ft_printf("pb\n");
}
