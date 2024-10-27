/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:31:30 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/27 19:21:46 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	a->i = 0;
	a->j = 0;
}

void	free_t_tab(t_tab *a, t_tab *b)
{
	free(a->tab);
	free(a);
	free(b->tab);
	free(b);
	return ;
}

void	free_args(char **args)
{
	int	i;

	if (args != NULL)
	{
		i = 0;
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}
