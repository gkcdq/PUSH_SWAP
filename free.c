#include "push_swap.h"

void	free_t_tab(t_tab *a, t_tab *b)
{
		free(a->tab);
		free(a);
		free(b->tab);
		free(b);
		return ;
}