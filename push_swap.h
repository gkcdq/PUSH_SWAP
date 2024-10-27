/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:56:00 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/26 22:34:23 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_tab
{
	int	*tab;
	int	size;
	int	top;
	int	median;
	int	cheapest;
	int	target;
	int	size_tab;
	int	i;
	int	j;
	int	ac;
}		t_tab;

// moovement_fonctions

// push
void	pa(t_tab *a, t_tab *b);
void	pb(t_tab *a, t_tab *b);
// rotate
void	ra(t_tab *a);
void	rb(t_tab *b);
void	rr(t_tab *a, t_tab *b);
// reverse_rotate
void	rra(t_tab *a);
void	rrb(t_tab *b);
void	rrr(t_tab *a, t_tab *b);
// swap
void	sa(t_tab *a);
void	sb(t_tab *b);
void	ss(t_tab *a, t_tab *b);

// src_fonctions

void	verif2(char **args, char *arg, t_tab *a, t_tab *b);
char	**parse_and_get_size(int ac, char **av, int *size);
void	rotate_or_push_a(t_tab *a, t_tab *b);
void	verif(char **args, char *arg, t_tab *a, t_tab *b);
int		ft_is_valid_number(char *str);
void	ft_check_double(t_tab *a, t_tab *b, char **args);
void	ft_compare_int(t_tab *a, t_tab *b, char **args);
void	free_args(char **args);
int		ft_atol(char *str);
void	check_atol(long number, int sign);
int		ft_check_tri(t_tab *a);
char	**push_swap_split(char *str);
void	ft_freetab(char **strs);
void	sort_tree(t_tab *a);
t_tab	*init_stack(int size);
void	free_t_tab(t_tab *a, t_tab *b);
int		ft_check_tri(t_tab *a);
void	ft_swap(int *a, int *b);
int		sort_in_tab_to_median(t_tab *a);
void	ft_parsing(int ac, char **av, t_tab *a, t_tab *b);
void	algorithm(t_tab *a, t_tab *b);
int		find_max(t_tab *a);
void	copy_tab(t_tab *a, int *tab);
void	rotate_or_push_to_sort_tree_to_algorithm_to_max(t_tab *a, t_tab *b);
void	alloc_tab(t_tab **a, t_tab **b, int ac, char **av);
int		find_target_index_in_a(t_tab *a, int cheapest);
int		find_cheapest_index_in_b(t_tab *b);
void	rotate_both(t_tab *a, t_tab *b);
void	reverse_rotate_both(t_tab *a, t_tab *b);
void	init_struct_value(t_tab *a, t_tab *b);

#endif
