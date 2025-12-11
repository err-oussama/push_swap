#ifndef SORT_H
# define SORT_H

# include "../push_swap.h"

typedef struct s_sorted_array
{
	int	size;
	int	*arr;
}		t_sorted_array;

void	sort_3(t_stack *a);

void	sort_small_stack(t_stack *a, t_stack *b);

void	sort_array(t_sorted_array *arr);

void	sort_4(t_stack *a, t_stack *b, int *arr);

void	sort_5(t_stack *a, t_stack *b, int *arr);
void	fill_sort_array(t_sorted_array *arr, t_stack *a);

#endif
