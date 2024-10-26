/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:39:35 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/26 22:31:45 by tmilin           ###   ########.fr       */
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

int	*reverse_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < (size / 2))
	{
		ft_swap(&tab[i], &tab[size - i - 1]);
		i++;
	}
	return (tab);
}

void	init_struct_value(t_tab *a, t_tab *b)
{
	a->median = 0;
	b->median = 0;
	a->target = 0;
	b->target = 0;
	a->cheapest = 0;
	b->cheapest = 0;
	a->size_tab = 0;
	b->size_tab = 0;
	a->args = NULL;
}

int	main(int ac, char **av)
{
	t_tab	*a;
	t_tab	*b;
	int		size;
	char	**args;
	int		max;

	if (ac < 2)
		return (0);
	a = init_stack(ac - 1);
	b = init_stack(ac - 1);
	if (ac == 2)
	{
		free_t_tab(a, b);
		size = 0;
		args = push_swap_split(av[1]);
		while (args[size])
			size++;
		a = init_stack(size);
		b = init_stack(size);
		free_args(args);
	}
	init_struct_value(a, b);
	ft_parsing(ac, av, a, b);
	reverse_tab(a->tab, a->size);
	a->median = sort_in_tab_to_median(a);
	if (a->top <= 2)
		sort_tree(a);
	while (!ft_check_tri(a) && a->top > 2)
	{
		rotate_or_push_a(a, b);
		if (a->top <= 2)
			sort_tree(a);
	}
	while (b->top > -1)
	{
		turk_algorithm(a, b);
	}
	max = find_max(a);
	while (a->tab[0] != max)
		ra(a);
	free_t_tab(a, b);
}
