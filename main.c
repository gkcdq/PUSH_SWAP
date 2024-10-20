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

t_tab	*init_stack(int size)
{
	t_tab	*stack;

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

int	main(int ac, char **av)
{
	t_tab	*a;
	t_tab	*b;
	int		k;

	if (ac < 2)
		return (0);
	a = init_stack(ac - 1);
	b = init_stack(ac - 1);
	if (!a || !b)
		free_t_tab(a, b);
	ft_parsing(ac, av, a);
	if (a->top == 2)
		sort_tree(a);
	if (a->top > 2)
	{
		push_initial_two(a, b);
		if (a->top <= 2)
			sort_tree(a);
	}
	while (!ft_check_tri(a) && a->top > 2)
	{
		rotate_or_push_a(a, b);
	}
	k = 0;
	ft_printf("\npile a\n");
	while (k < a->top + 1)
	{
		ft_printf("\n%d", a->tab[k]);
		k++;
	}
	return (0);
}
