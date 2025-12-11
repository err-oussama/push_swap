
#include "push_swap.h"
#include "sort/sort.h"

void	third_step(t_stack *a, t_stack *b)
{
	//if (a->size < 5)
		return (sort_small_stack(a, b));	
}


int second_step(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
		third_step(*a,*b);
//	display(*a);
	clear(a);
	clear(b);
	return (0);
}
