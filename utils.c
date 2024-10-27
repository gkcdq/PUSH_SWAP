/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:34:32 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/26 23:20:45 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	check_atol(number, sign);
	return (sign * number);
}

void	check_atol(long number, int sign)
{
	if (number * sign > INT_MAX || number * sign < INT_MIN)
	{
		ft_printf("Error\n");
		exit(0);
	}
}

int	ft_check_tri(t_tab *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->tab[i] > a->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_freetab(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}