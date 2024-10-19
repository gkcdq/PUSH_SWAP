/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:39:35 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/18 15:39:37 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_tri(t_tab *a)
{
    int i;

    i = 0;
    while (i < a->top)
    {
        if (a->tab[i] > a->tab[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void sort_jpp(t_tab *a)
{
        // 3 1 2
        if (a->tab[0] > a->tab[1] && a->tab[0] > a->tab[2] && a->tab[1] < a->tab[2])
            rra(a);
        // 1 3 2
        else if (a->tab[0] < a->tab[1] && a->tab[0] < a->tab[2] && a->tab[1] > a->tab[2])
        {
            sa(a);
            ra(a);
        }
        // 2 1 3
        else if (a->tab[0] > a->tab[1] && a->tab[0] < a->tab[2] && a->tab[1] < a->tab[2])
            sa(a);
        // 2 3 1
        else if (a->tab[0] < a->tab[1] && a->tab[0] > a->tab[2] && a->tab[1] > a->tab[2])
            rra(a);
        // 3 2 1
        else if (a->tab[0] > a->tab[1] && a->tab[1] > a->tab[2])
        {
            sa(a);
            rra(a);
    }
}
t_tab *init_stack(int size)
{
    t_tab *stack;

    stack = malloc(sizeof(t_tab));
    if (!stack)
        return (NULL);
    stack->tab = malloc(sizeof(int) * size);
    if (!stack->tab)
    {
        free(stack);
        return (NULL);
    }
    stack->top = -1;
    stack->size = size;
    return (stack);
}

int main(int ac, char **av)
{
    t_tab *a;
    t_tab *b;

    if (ac < 2)
        return (0);
    a = init_stack(ac - 1);
    b = init_stack(ac - 1);
    if (!a || !b)
        free_t_tab(a, b);
    ft_parsing(ac, av, a);
    if (a->top == 2)
        sort_jpp(a);
    else if (!ft_check_tri(a) && a->top > 3)
        //xxxxxxxxxxxx
    free_t_tab(a, b);
    return (0);
}

