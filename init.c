#include "push_swap.h"

void    ft_parsing(int ac, char **av, t_tab *a)
{
    int i;

    i = 0;
    if (ac < 2)
        return ;
    while (i++ < ac)
    {
        ft_split(av[1], ' ');
        a->tab[++a->top] = ft_atoi(av[i]);
        if(!ft_is_valid_number(av[i]))
        {
            ft_printf("Error\n");
            exit (0);
        }
    }
    ft_check_stack(a);
    //gerer int min / max
}
int ft_is_valid_number(char *str)
{
    int i;

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

static void ft_compare_int(int a, int b)
{
    if (a == b)
    {
        ft_printf("Error\n");
        exit (1);
    }
}

void    ft_check_stack(t_tab *a)
{
    int i;
    int j;

    i = a->top;
    if (!a || a->top < 1)
        return 0;
    while (i > 0)
    {
        j = i - 1;
        while (j >= 0)
        {
            ft_compare_int(a->tab[i], a->tab[j]);
            j--;
        }
        i--;
    }
}

/*t_tab *init_stack(int size)
{
    t_tab *stack;

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
}*/