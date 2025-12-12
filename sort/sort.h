#ifndef SORT_H
# define SORT_H

# include "push_swap.h"
#include "../push_swap.h"
typedef struct s_sorted_array
{
	int	size;
	int	*arr;
}		t_sorted_array;


void	sort_larg_stack(t_stack *a, t_stack *b, int *arr);
void	sort_small_stack(t_stack *a, t_stack *b);

void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b, int *arr);
void	sort_5(t_stack *a, t_stack *b, int *arr);

size_t to_top_cost(t_stack *stack, size_t index);
size_t insert_cost(t_stack *stack, size_t index);
size_t to_top(t_stack *stack, size_t index, char c);
void insert(t_stack *a, t_stack *b, size_t index, char c);

void	sort_array(t_sorted_array *arr);
void	fill_sort_array(t_sorted_array *arr, t_stack *a);







#endif
