/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:56:00 by tmilin            #+#    #+#             */
/*   Updated: 2024/10/18 15:46:06 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

//# define INT_MAX 2147483647
//# define INT_MIN -2147483648
# define CHUNK_SIZE 50

typedef struct s_tab
{
	int		*tab;
	int		size;
	int		top;
}	t_tab;

//moovement_fonctions

void    pa(t_tab *a, t_tab *b);	//		push a (push 1er element de b dans a)
void    pb(t_tab *a, t_tab *b);	//		push b (push 1er element de a dans b)

void    ra(t_tab *a); 			//		rotate a (decale tout vers le haut, le top devient le bot)
void    rb(t_tab *b);			//		rotate b (decale tout vers le haut, le top devient le bot)
void    rr(t_tab *a, t_tab *b);	//		(rotate a et b en meme temps (ra et rb))

void    rra(t_tab *a); 			//		reverse rotate a (decale tout vers le bas, le bot devient le top)
void    rrb(t_tab *b);			//		reverse rotate b (decale tout vers le bas, le bot devient le top)
void    rrr(t_tab *a, t_tab *b);//		(reverse rotate a et b (rra, rrb))

void    sa(t_tab *a);			//		swap a (2 premiers elements du top)
void    sb(t_tab *b); 			//		swap b (2 premiers elements du top)
void    ss(t_tab *a, t_tab *b);	//		swap a et b (2 premiers elements des 2 top)

//algo1.c
void    rotate_or_push_a(t_tab *a, t_tab *b);

//parsing.c
void    ft_parsing(int ac, char **av, t_tab *a);
void verif(char *arg);
int ft_is_valid_number(char *str);
void    ft_check_double(t_tab *a);
void ft_compare_int(int a, int b);
void free_args(char **args);

//utils.c
int		ft_atol(char *str);
void    check_atol(long number, int sign);
int ft_check_tri(t_tab *a);
char    **push_swap_split(char *str);
void ft_freetab(char **strs);

void	sort_tree(t_tab *a);

t_tab *init_stack(int size);
void    free_t_tab(t_tab *a, t_tab *b);
int ft_check_tri(t_tab *a);
void    push_initial_two(t_tab *a, t_tab *b);


void ft_parsing(int ac, char **av, t_tab *a);


#endif
