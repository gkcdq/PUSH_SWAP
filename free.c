/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:31:30 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/26 22:31:32 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_t_tab(t_tab *a, t_tab *b)
{
	free(a->tab);
	free(a);
	free(b->tab);
	free(b);
	return ;
}

void	free_t_tab_a(t_tab *a)
{
	free(a->tab);
	free(a);
	return ;
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
