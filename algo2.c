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

    i = a->top;
    while (i >= 0)
    {
        if (a->tab[i] > cheapest)
            return (i);
        i--;
    }
    return (0);
}

static void rotate_both(t_tab *a, t_tab *b)
{
    while (b->tab[b->top] != b->cheapest && a->tab[a->top] != a->target)
        rr(a, b);
}
static void reverse_rotate_both(t_tab *a, t_tab *b)
{
    while (b->tab[b->top] != b->cheapest && a->tab[a->top] != a->target)
        rrr(a, b);
}

void before_push_a(t_tab *a, int target_index)
{
    if (a->top < 0)
        return ;
    while (a->target != a->tab[a->top])
    {
        if (target_index < a->size_tab)
            rra(a);
        else if (target_index >= a->size_tab)
            ra(a);
    }
}
void before_push_b(t_tab *b, int cheapest_index)
{
    if (b->top < 0)
        return ;
    while (b->cheapest != b->tab[b->top])
    {
        if (cheapest_index < b->size_tab)
            rrb(b);
        else if (cheapest_index >= b->size_tab)
            rb(b);
    }
}

void calculate_size(t_tab *x)
{
    x->size_tab = x->top / 2;
}

void turk_algorithm(t_tab *a, t_tab *b)
{
    int best_move_index;
    int target_index;


    best_move_index = find_cheapest_index_in_b(b);
    //ft_printf("cheapest_index = %d\n", cheapest_index);
    b->cheapest = b->tab[best_move_index];
    //ft_printf("b->cheapest = %d\n", b->cheapest);
    target_index = find_target_index_in_a(a, b->cheapest);
    //ft_printf("target_index = %d\n", target_index);
    a->target = a->tab[target_index];
    //ft_printf("a->target = %d\n", a->target);
    if (best_move_index >= b->size_tab && target_index >= a->size_tab)
        rotate_both(a, b);
    else if (best_move_index < b->size_tab && target_index < a->size_tab)
        reverse_rotate_both(a, b);
    before_push_a(a, target_index);
    before_push_b(b, best_move_index);
    pa(a, b);
    calculate_size(a);
    calculate_size(b);
}

/*static int calculate_rotation_cost(t_tab *stack, int index)
{
    if (index <= stack->top / 2)
        return (index);  // rotation normale
    else
        return (stack->top - index + 1); // rotation inversée
}

static int calculate_cost(t_tab *a, t_tab *b, int index_b)
{
    int cost_a;
    int cost_b;
    int target_index;

    target_index = find_target_index_in_a(a, b->tab[index_b]);
    cost_a = calculate_rotation_cost(a, target_index);
    cost_b = calculate_rotation_cost(b, index_b);
    return (cost_a + cost_b);
}

static int calculate_best_move(t_tab *a, t_tab *b)
{
    int best_index;
    int min_cost;
    int cost;
    int i;

    best_index = 0;
    min_cost = INT_MAX;
    i = 0;
    while (i <= b->top)
    {
        cost = calculate_cost(a, b, i);
        if (cost < min_cost)
        {
            min_cost = cost;
            best_index = i;
        }
        i++;
    }
    return (best_index);
}

void turk_algorithm(t_tab *a, t_tab *b)
{
    int best_index;
    int target_index;

    best_index = calculate_best_move(a, b);
    b->cheapest = b->tab[best_index];
    target_index = find_target_index_in_a(a, b->cheapest);
    a->target = a->tab[target_index];

    if (best_index >= b->size_tab && target_index >= a->size_tab)
        rotate_both(a, b);
    else if (best_index < b->size_tab && target_index < a->size_tab)
        reverse_rotate_both(a, b);
    before_push_a(a, target_index);
    before_push_b(b, best_index);
    pa(a, b);
    calculate_size(a);
    calculate_size(b);
}*/







