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

t_tab *init_stack(int size)
{
    t_tab *stack;

    stack = malloc(sizeof(t_tab));
    if (!stack)
        return NULL;
    stack->tab = malloc(sizeof(int) * size);
    if (!stack->tab) {
        free(stack);
        return NULL;
    }
    stack->top = -1;
    stack->size = size;
    return stack;
}

int main(int ac, char **av) 
{
    if (ac < 2)
        return 0;

    t_tab *a = init_stack(ac - 1);
    t_tab *b = init_stack(ac - 1);
    if (ac == 2)
    {
		free_t_tab(a, b);
        int size = 0;
        char **args = push_swap_split(av[1]);
        while (args[size])
            size++;
        a = init_stack(size);
        b = init_stack(size);
		free_args(args);
    } 
    //reverse a->tab
    ft_parsing(ac, av, a);
    //if (!ft_check_tri(a) && a->top > 2) 
	//{
        //a->median = sort_in_tab_to_median(a);
        //ft_printf("median = %d\n", a->median);
        //push_initial_two(a, b);
    //}
    a->median = sort_in_tab_to_median(a);
   // ft_printf("median = %d\n", a->median);
    while (!ft_check_tri(a)) 
	{
        if (a->top <= 2)
            sort_tree(a);
        else if (a->top > 2)
            rotate_or_push_a(a, b);
    }



    int k = 0;
    ft_printf("\npile a\n");
    while (k <= a->top) 
	{
        ft_printf("%d\n", a->tab[k]);
        k++;
    }
    k = 0;
    ft_printf("\npile b\n");
    while (k <= b->top) {
        ft_printf("%d\n", b->tab[k]);
        k++;
    }
    free_t_tab(a, b);
    return 0;
}

