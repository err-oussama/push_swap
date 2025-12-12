#include "sort.h"
#include <stddef.h>

size_t to_top_cost(t_stack *stack, size_t index)
{
    if (index >= (stack->size / 2))
        return (stack->size - index);
    return (index);
}

size_t insert_cost(t_stack *stack, size_t index)
{
    return ((to_top_cost(stack, index) * 2) + 1); 
}


size_t to_top(t_stack *stack, size_t index, char c)
{
    size_t cost;
    size_t ret;

    cost = to_top_cost(stack, index);
    ret = cost;    
    if (index < (stack->size / 2))
        while (cost--)
            rotate(stack,c);
    else
        while (cost--)
            rev_rotate(stack, c);
    return (ret);
}


static void restor_after_insert(t_stack *stack, size_t index, size_t cost, char c)
{
    if (((stack->size - 1) / 2) > index)
        while (cost--)
            rev_rotate(stack, c);
    else
    {
        while (cost--)
            rotate(stack, c);
        rotate(stack, c);    
    }   
}

void insert(t_stack *a, t_stack *b, size_t index, char c)
{
    size_t cost;

    if (c == 'a')
        cost = to_top(a, index, 'a');
    else if (c == 'b')
        cost = to_top(b, index, 'b');
    push_op(a, b, c);
    if (c == 'a')
        restor_after_insert(a, index, cost, c);
    else
        restor_after_insert(b, index, cost, c); 
}
