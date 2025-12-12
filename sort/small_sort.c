#include "sort.h"


void	sort_3(t_stack *a)
{
	if (a->head->next->n > a->head->n && a->head->next->n > a->tail->n)
		rev_rotate(a, 'a');
	else if (a->head->n > a->head->next->n && a->head->n > a->tail->n)
		rotate(a, 'a');
	if (a->head->next->n < a->head->n)
		swap(a, 'a');
}

void	sort_4(t_stack *a, t_stack *b, int *arr)
{
	int	index;

	index = search(a, arr[0]);
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

void	sort_5(t_stack *a, t_stack *b, int *arr)
{
	int	index;

	index = search(a, arr[0]);
	if (index == 1)
		swap(a, 'a');
	else if (index == 4)
		rev_rotate(a, 'a');
	else if (index == 3 || index == 2)
			while (index++ < 5)
				rev_rotate(a, 'a');
	push_op(a,b,'b');
	sort_4(a,b, &arr[1]);
	push_op(a, b, 'a');
}
