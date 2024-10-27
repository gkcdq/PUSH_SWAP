/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:34:14 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/26 22:34:15 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_and_get_size(int ac, char **av, int *size)
{
	char	**args;

	args = NULL;
	if (ac == 2)
	{
		args = push_swap_split(av[1]);
		*size = 0;
		while (args[*size])
		{
			(*size)++;
		}
	}
	else
	{
		args = av + 1;
		*size = ac - 1;
	}
	return (args);
}

void	ft_parsing(int ac, char **av, t_tab *a, t_tab *b)
{
	int		i;
	char	**args;
	int		size;

	i = 0;
	args = parse_and_get_size(ac, av, &size);
	while (i < size)
	{
		if (ac == 2)
			verif(args, args[i], a, b);
		else
			verif2(args, args[i], a, b);
		a->tab[++a->top] = ft_atol(args[i]);
		i++;
	}
	ft_check_double(a, b, args);
	if (ac == 2)
		free_args(args);
}

void	verif(char **args, char *arg, t_tab *a, t_tab *b)
{
	if (!ft_is_valid_number(arg))
	{
		ft_printf("Error\n");
		free_t_tab(a, b);
		free_args(args);
		exit(1);
	}
}

void	verif2(char **args, char *arg, t_tab *a, t_tab *b)
{
	(void)args;
	if (!ft_is_valid_number(arg))
	{
		ft_printf("Error\n");
		free_t_tab(a, b);
		exit(1);
	}
}
