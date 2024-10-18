/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:39:51 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/18 15:39:52 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_tab *a, t_tab *b)
{
    int x_b;
    
    if (!a || !b || (b->top == -1))
        return ;
    x_b = b->tab[b->top];
    if (a->top + 1 >= a->size)
        return ;
    a->top++;
    a->tab[a->top] = x_b;
    b->top--;
    ft_printf("pa\n");
}
