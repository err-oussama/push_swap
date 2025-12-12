#include "sort.h"
#include <stddef.h>

void	sort_larg_stack(t_stack *a, t_stack *b, int *arr)
{
    push_op(a,b, 'b');
	size_t best_const;
	size_t from;
	size_t to;
	size_t i;
	size_t megra;
    while(a->size > 5)
	{
		best_const = -1;
		i = 0;
		while (i < a->size)
		{
			megra = megration_cost(a,b, i, get_pos_dec(b, get_index(a,i)));
//			printf("megra => %li\n", megra);
			if (megra < best_const)
			{
				from = i;
				to = get_pos_dec(b,get_index(a,i));
				best_const = megra;
			}
			i++;
		}
//		printf("best cost ==>> %li\n", best_const);
		to_top(a, from, 'a');
		insert(a, b, to, 'b');
	}
	for (int i = 0; i < 4; i++)
		if (i > arr[i])
			i++;
	t_sorted_array gg;
	gg.arr = malloc(5);
	gg.size = 5;
	fill_sort_array(&gg,a);
	sort_array(&gg);
	sort_5(a, b, gg.arr);

printf("=========================================\n");
while(b->size)
	{
		best_const = -1;
		i = 0;
	
		display(a);
		printf("========================\n");
		display(b);
		while (i < b->size)
		{
			megra = megration_cost(b,a, i, get_pos_inc(a, get_index(b,i)));
			printf("megra => %li\n", megra);
			if (megra < best_const)
			{
				from = i;
				to = get_pos_inc(a,get_index(b,i));
				best_const = megra;
			}
			i++;
		}
	printf("to -> %li\n", to);
		insert(a, b, to, 'a');
	}
}

