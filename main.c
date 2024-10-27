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

int	main(int ac, char **av)
{
	t_tab	*a;
	t_tab	*b;

	a = NULL;
	b = NULL;
	alloc_tab(&a, &b, ac, av);
	init_struct_value(a, b);
	ft_parsing(ac, av, a, b);
	reverse_tab(a->tab, a->size);
	a->median = sort_in_tab_to_median(a);
	rotate_or_push_to_sort_tree_to_algorithm_to_max(a, b);
	free_t_tab(a, b);
	return (0);
}

void	alloc_tab(t_tab **a, t_tab **b, int ac, char **av)
{
	int		size;
	char	**args;

	if (ac < 2)
		return ;
	*a = init_stack(ac - 1);
	*b = init_stack(ac - 1);
	if (ac == 2)
	{
		free_t_tab(*a, *b);
		size = 0;
		args = push_swap_split(av[1]);
		while (args[size])
			size++;
		*a = init_stack(size);
		*b = init_stack(size);
		free_args(args);
	}
}

void	rotate_or_push_to_sort_tree_to_algorithm_to_max(t_tab *a, t_tab *b)
{
	int	max;

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
		algorithm(a, b);
	}
	max = find_max(a);
	while (a->tab[0] != max)
		ra(a);
}
