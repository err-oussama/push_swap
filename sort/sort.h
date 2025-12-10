#ifndef SORT_H
#define SORT_H

#include "../push_swap.h"
typedef struct s_sorted_array {
	int size;
	int *arr;
}t_sorted_array;

void	sort_small_stack(t_stack *a);
void	set_sorted_number(t_sorted_array * arr, t_stack *a);

#endif
