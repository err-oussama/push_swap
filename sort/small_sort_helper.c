#include "sort.h"

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

