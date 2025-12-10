#include "sort.h"
#include <strings.h>

void	sort_small_stack(t_stack *a, t_stack *b)
{
	t_sorted_array	arr;

	if (a->size == 2)
		return (swap(a, 'a'));
	if (a->size == 3)
		return (sort_3(a));
	arr.size = a->size;
	arr.arr = c_alloc(a->size, sizeof(int));
	if (!arr.arr)
		return ;
	fill_sort_array(&arr, a);
	if (a->size == 4)
		return (sort_4(a,b, &arr));
}

void	sort_3(t_stack *a)
{
	if (a->head->next->n > a->head->n && a->head->next->n > a->tail->n)
		rev_rotate(a, 'a');
	else if (a->head->n > a->head->next->n && a->head->n > a->tail->n)
		rotate(a, 'a');
	if (a->head->next->n < a->head->n)
		swap(a, 'a');
}

void	fill_sort_array(t_sorted_array *arr, t_stack *a)
{
	t_node	*tmp;
	int		i;

	tmp = a->head;
	i = 0;
	while (tmp)
	{
		arr->arr[i++] = tmp->n;
		tmp = tmp->next;
	}
	sort_array(arr);
}

void	sort_array(t_sorted_array *arr)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < arr->size)
	{
		j = i;
		while (++j < arr->size)
		{
			if (arr->arr[i] > arr->arr[j])
			{
				t = arr->arr[i];
				arr->arr[i] = arr->arr[j];
				arr->arr[j] = t;
			}
		}
		i++;
	}
}

void	sort_4(t_stack *a, t_stack *b, t_sorted_array *arr)
{
	int	index;

	index = search(a, arr->arr[0]);
	if (index == 0)
		push_op(a, b, 'b');
	else if (index == 1)
		swap(a, 'a');
	else if (index == 3)
		rev_rotate(a, 'a');
	else
	{
		rev_rotate(a, 'a');
		rev_rotate(a, 'a');
	}
	push_op(a, b, 'b');
	sort_3(a);
	push_op(a, b, 'a');
}
