#include "push_swap.h"

char **parse_and_get_size(int ac, char **av, int *size)
{
    char **args = NULL;

    if (ac == 2)
    {
        args = push_swap_split(av[1]);
        *size = 0;
        while (args[*size])
            (*size)++;
    }
    else
    {
        args = av + 1;
        *size = ac - 1;
    }
    return args;
}

void ft_parsing(int ac, char **av, t_tab *a)
{
    int i;
    char **args;
    //int size;

    i = 0;
    args = parse_and_get_size(ac, av, &a->size);
    while (i < a->size)
    {
        verif(args[i]);
        a->tab[++a->top] = ft_atol(args[i]);
        i++;
    }
    ft_check_double(a);
    if (ac == 2)
        free_args(args);
}

void verif(char *arg)
{
    if (!ft_is_valid_number(arg))
    {
        ft_printf("Error\n");
        exit(1);
    }
}

int ft_is_valid_number(char *str)
{
    long int i;

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

void    ft_check_double(t_tab *a)
{
    int i;
    int j;

    i = a->top;
    if (!a || a->top < 1)
        return ;
    while (i > 0)
    {
        j = i - 1;
        while (j > 0)
        {
            ft_compare_int(a->tab[i], a->tab[j]);
            j--;
        }
        i--;
    }
}
void ft_compare_int(int a, int b)
{
    if (a == b)
    {
        ft_printf("Error\n");
        exit (1);
    }
}

void free_args(char **args)
{
    int i = 0;

    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}