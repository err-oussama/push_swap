#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>



int get_chunk_size(t_stack *stack)
{
	if (stack->size <= 100)
		return (20);
	if (stack->size <= 500)
		return (44);
	return (100);
}

void best_move(t_stack *a, t_stack *b, size_t start, size_t end)
{
    t_node *tmp;
    size_t i;
    size_t best_pos;
    size_t best_cost;
    size_t chunk_mid;

    chunk_mid = start + (end - start) / 2;  // middle of the chunk

    tmp = a->head;
    i = 0;
    best_cost = -1;   // use SIZE_MAX for safety
    best_pos  = 0;

    while (tmp)
    {
        if (start <= tmp->index && tmp->index < end)
        {
            size_t cost = to_top_cost(a, i);
            if (cost < best_cost)
            {
                best_cost = cost;
                best_pos = i;
            }
        }
        i++;
        tmp = tmp->next;
    }

    to_top(a, best_pos, 'a');
    push_op(a, b, 'b');

    // Partial ordering in B
    if (b->head->index < chunk_mid)
        rotate(b, 'b');
}

void push_chunk_to_b(t_stack *a, t_stack *b, size_t chunk_size)
{
	size_t i;
	size_t start;
	size_t end;

	start = 0;
	end = chunk_size;
	while (a->size > 5)
	{
		i = -1;
		while(++i < chunk_size && a->size > 5)
			best_move(a, b, start, end);
		start+=chunk_size;
		end+=chunk_size;
	}	
}

void best_move_a(t_stack *a, t_stack *b)
{
	t_node *tmp;
	size_t i;
	size_t best_pos;
	size_t best_cost;
	
	tmp = b->head;
	i = 0;
	best_cost = -1;
	best_pos = -1;
	while (tmp)
	{
		if (best_cost > megration_cost(b, a, i, get_pos_inc(a,tmp->value)))
		{
			best_cost = megration_cost(b, a, i, get_pos_inc(a, tmp->value));
			best_pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	to_top(b, best_pos, 'b');
	insert(a, b, get_pos_inc(a, b->head->value), 'a');
}


void	sort_larg_stack(t_stack *a, t_stack *b)
{
	int *arr;
	int chunk_size;

	chunk_size = get_chunk_size(a);
	arr = indexing(a);
	if (!arr)
		return;
	push_chunk_to_b(a, b, chunk_size);
	sort_5(a,b);
	while(b->size)
		best_move_a(a, b);
	free(arr);
}
