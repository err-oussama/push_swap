#include "sort.h"
#include <stddef.h>

size_t	to_top_cost(t_stack *stack, size_t index)
{
	if (index >= (stack->size / 2))
		return (stack->size - index);
	return (index);
}

size_t	to_top(t_stack *stack, size_t index, char c)
{
	size_t	cost;
	size_t	ret;

	cost = to_top_cost(stack, index);
	ret = cost;
	if (index < (stack->size / 2))
		while (cost--)
			rotate(stack, c);
	else
		while (cost--)
			rev_rotate(stack, c);
	return (ret);
}
