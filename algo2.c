#include "push_swap.h"

static int  find_cheapest_index_in_b(t_tab *b)
{
    int cheapest_index = -1;
    int cheapest_value = INT_MAX;
    int i;

    i = 0;
    while (i <= b->top)
    {
        if (b->tab[i] < cheapest_value)
        {
            cheapest_value = b->tab[i];
            cheapest_index = i;
        }
        i++;
    }
    return cheapest_index;
}

static int  find_target_index_in_a(t_tab *a, int cheapest)
{
    int i;

    i = 0;
    while (i <= a->top)
    {
        if (a->tab[i] > cheapest)
            return (i);
        i++;
    }
    return (0);
}

static void rotate_both(t_tab *a, t_tab *b)
{
    while (b->tab[b->top] != b->cheapest && a->tab[a->top] != a->target)
        rr(a, b);
    //a->median = sort_in_tab_to_median(a);
    //b->median = sort_in_tab_to_median(b);
    ft_printf("a->median = %d\n", a->median);
    ft_printf("b->median = %d\n", b->median);
}
static void reverse_rotate_both(t_tab *a, t_tab *b)
{
    while (b->tab[b->top] != b->cheapest && a->tab[a->top] != a->target)
        rrr(a, b);
    //a->median = sort_in_tab_to_median(a);
    //b->median = sort_in_tab_to_median(b);
    ft_printf("a->median = %d\n", a->median);
    ft_printf("b->median = %d\n", b->median);
}

void before_push(t_tab *stack, int index, char c)
{
    if (stack->top < 0)
        return ;
    if (c == 'a')
    {
        while (stack->tab[stack->top] != stack->target)
        {
            if (index >= stack->median)
                rra(stack);
            else
                ra(stack);
        }
    }
    else if (c == 'b')
    {
        while (stack->tab[stack->top] != stack->cheapest)
        {
            if (index >= stack->median)
                rra(stack);
            else
                ra(stack);
        }

    }

}

void turk_algorithm(t_tab *a, t_tab *b)
{
    int cheapest_index;
    int target_index;


    cheapest_index = find_cheapest_index_in_b(b);
    ft_printf("cheapest_index = %d\n", cheapest_index);
    b->cheapest = b->tab[cheapest_index];
    ft_printf("b->cheapest = %d\n", b->cheapest);
    target_index = find_target_index_in_a(a, b->cheapest);
    ft_printf("target_index = %d\n", target_index);
    a->target = a->tab[target_index];
    ft_printf("a->target = %d\n", a->target);
    //a->median = sort_in_tab_to_median(a);
   // b->median = sort_in_tab_to_median(b);
    if (cheapest_index >= b->median && target_index >= a->median)
        rotate_both(a, b);
    else if (cheapest_index < b->median && target_index < a->median)
        reverse_rotate_both(a, b);
    before_push(a, target_index, 'a');
    before_push(b, cheapest_index, 'b');
    pa(a, b);
    a->median = sort_in_tab_to_median(a);
    b->median = sort_in_tab_to_median(b);
}

/*static int find_cheapest_value_in_b(t_tab *b)
{
    long    x;
    int i = 0;

    x = LONG_MAX;
    while (i <= b->top)
    {
        if (b->tab[i] < x)
            x = b->tab[i];
        i++;
    }
    return ((int)x);
}*/



