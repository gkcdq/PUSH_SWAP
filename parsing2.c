/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:45:02 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/27 15:45:03 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_check_double(t_tab *a, t_tab *b, char **args, int ac)
{
	a->i = 0;
	if (!a || a->top < 1)
		return ;
	while (a->i <= a->top)
	{
		a->j = a->i + 1;
		while (a->j <= a->top)
		{
			if (ac == 2)
				ft_compare_int(a, b, args);
			else
				ft_compare_int2(a, b, args);
			a->j++;
		}
		a->i++;
	}
}

void	ft_compare_int(t_tab *a, t_tab *b, char **args)
{
	if (a->tab[a->i] == a->tab[a->j])
	{
		ft_printf("Error\n");
		free_args(args);
		free_t_tab(a, b);
		exit(1);
	}
}

void	ft_compare_int2(t_tab *a, t_tab *b, char **args)
{
	(void)args;
	if (a->tab[a->i] == a->tab[a->j])
	{
		ft_printf("Error\n");
		free_t_tab(a, b);
		exit(1);
	}
}
