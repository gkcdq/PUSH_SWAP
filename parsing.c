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
		verif(args, args[i], a, b);
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

int	ft_is_valid_number(char *str)
{
	long int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_double(t_tab *a, t_tab *b, char **args)
{
	a->i = a->top;
	if (!a || a->top < 1)
		return ;
	while (a->i > 0)
	{
		a->j = a->i - 1;
		while (a->j > 0)
		{
			ft_compare_int(a, b, args);
			a->j--;
		}
		a->i--;
	}
}

void	ft_compare_int(t_tab *a, t_tab *b, char **args)
{
	if (a->i == a->j)
	{
		ft_printf("Error\n");
		free_args(args);
		free_t_tab(a, b);
		exit(1);
	}
}
