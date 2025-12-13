#include "sort.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

void	sort_butterfly(t_stack *a, t_stack *b)
{
	size_t	chunk_size;
	size_t	pushed;

	pushed = 0;
	chunk_size = get_chunk_size(a->size);
	while (a->size)
	{
		if (a->head->index <= pushed)
		{
			push_op(a, b, 'b');
			rotate(b, 'b');
			pushed++;
		}
		else if (a->head->index <= pushed + chunk_size)
		{
			push_op(a, b, 'b');
			pushed++;
		}
		else
			rotate(a, 'a');
	}
}

void	push_to_a(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	size_t	index;

	while (b->size)
	{
		tmp = b->head;
		index = 0;
		while (tmp)
		{
			if (tmp->index == b->size - 1)
			{
				to_top(b, index, 'b');
				push_op(a, b, 'a');
				break ;
			}
			tmp = tmp->next;
			index++;
		}
	}
}

void	sort_larg_stack(t_stack *a, t_stack *b)
{
	int	arr;

	arr = indexing(a);
	if (!arr)
		return ;
	sort_butterfly(a, b);
	push_to_a(a, b);
}
