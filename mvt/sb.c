/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:42:01 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/18 15:42:02 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sb(t_tab *b)
{
    int tmp;

    if (!b || b->top < 1)
        return ;
    tmp = b->tab[b->top];
    b->tab[b->top] = b->tab[b->top - 1];
    b->tab[b->top - 1] = tmp;
    ft_printf("sb\n");
}
