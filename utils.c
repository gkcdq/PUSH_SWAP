#include "push_swap.h"

int	ft_atol(const char *str)
{
	int	    i;
	int	    sign;
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

void    check_atol(long number, int sign)
{
    if (number * sign > INT_MAX || number * sign < INT_MIN)
    {
        ft_printf("Error\n");
        exit (0);
    }
}

int ft_check_tri(t_tab *a)
{
    int i;

    i = 0;
    while (i < a->top)
    {
        if (a->tab[i] > a->tab[i + 1])
            return (0);
        i++;
    }
    return (1);
}


////////////////////////////////////////////////////////////




static void ft_freetab(char **strs)
{
    int i;

    if (!strs)
        return;
    i = 0;
    while (strs[i])
    {
        free(strs[i]);
        i++;
    }
    free(strs);
}

static int ft_isspace(char c)
{
    if (c <= 32)
        return (1);
    return (0);
}

static int ft_count_words(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] && ft_isspace(str[i]))
            i++;
        if (str[i] && !ft_isspace(str[i]))
            count++;
        while (str[i] && !ft_isspace(str[i]))
            i++;
    }
    return (count);
}

static void    ft_putstrs(char **strs, char *str, int words)
{
    static int i;
    int j;
    int start;
    int end;

    j = 0;
    start = 0;
    while (str[start] && j < words)
    {
        i = 0;
        while (str[start] && ft_isspace(str[start]))
            start++;
        end = start;
        while (str[end] && !ft_isspace(str[end]))
            end++;
        strs[j] = malloc(sizeof(char) * (end - start + 1));
        if (!strs[j])
            return (ft_freetab(strs));
        while (start < end)
            strs[j][i++] = str[start++];
        strs[j++][i] = '\0';
    }
    strs[j] = 0;
}

char    **push_swap_split(char *str)
{
int words;
char    **strs;

    words = ft_count_words(str);
    if (!words)
        return (NULL);
    strs = malloc(sizeof(char *) * (words + 1));
    if (!strs)
        return (NULL);
    ft_putstrs(strs, str, words);
    return (strs);
}