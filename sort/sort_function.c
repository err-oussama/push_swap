
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


void	sort_small_stack(t_stack *a)
{
	t_sorted_array arr;

	if (a->size == 2)
		return (swap(a, 'a'));
	if (a->size == 3)
		return (sort_3(a));
	arr.size = a->size;
	arr.arr = c_alloc(a->size, sizeof(int));
	if (!arr.arr)
		return;
	set_sorted_number(&arr,a);

}
