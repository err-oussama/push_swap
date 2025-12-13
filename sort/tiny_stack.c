#include "sort.h"

void	sort_3(t_stack *a)
{
	if (a->head->next->value > a->head->value && a->head->next->value > a->tail->value)
		rev_rotate(a, 'a');
	else if (a->head->value > a->head->next->value && a->head->value > a->tail->value)
		rotate(a, 'a');
	if (a->head->next->value < a->head->value)
		swap(a, 'a');
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	index;

	index = search(a, get_min(a));
	if (index == 1)
		swap(a, 'a');
	else if (index == 3)
		rev_rotate(a, 'a');
	else if (index == 2)
	{
		rev_rotate(a, 'a');
		rev_rotate(a, 'a');
	}
	push_op(a, b, 'b');
	sort_3(a);
	push_op(a, b, 'a');
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	index;

	index = search(a, get_min(a));
	if (index == 1)
		swap(a, 'a');
	else if (index == 4)
		rev_rotate(a, 'a');
	else if (index == 3 || index == 2)
			while (index++ < 5)
				rev_rotate(a, 'a');
	push_op(a,b,'b');
	sort_4(a,b);
	push_op(a, b, 'a');
}
