#include "sort.h"
#include <stddef.h>

size_t megration_cost(t_stack *src, t_stack * dst, size_t from, size_t to)
{
		return (to_top_cost(src,from) + insert_cost(dst, to));
}

size_t insert_cost(t_stack *stack, size_t index)
{
    return ((to_top_cost(stack, index) * 2) + 1); 
}

size_t to_top_cost(t_stack *stack, size_t index)
{
    if (index >= (stack->size / 2))
        return (stack->size - index);
    return (index);
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

void insert(t_stack *a, t_stack *b, size_t index, char c)
{
    size_t cost;
	t_stack *dst;

    if (c == 'a')
        cost = to_top(a, index, 'a');
    else if (c == 'b')
        cost = to_top(b, index, 'b');
    push_op(a, b, c);
    if (c == 'a')
		dst = a;
    else
		dst = b;
    if (((dst->size - 1) / 2) > index)
        while (cost--)
            rev_rotate(dst, c);
    else
    {
        while (cost--)
            rotate(dst, c);
        rotate(dst, c);    
    }   
}
