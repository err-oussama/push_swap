#ifndef SORT_H
# define SORT_H

# include "push_swap.h"
#include "../push_swap.h"

void	sort_larg_stack(t_stack *a, t_stack *b);
void	sort_small_stack(t_stack *a, t_stack *b);

void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

size_t 	to_top_cost(t_stack *stack, size_t index);
size_t 	insert_cost(t_stack *stack, size_t index);
size_t 	to_top(t_stack *stack, size_t index, char c);
void 	insert(t_stack *a, t_stack *b, size_t index, char c);

void	fill_sort_array(int *arr, t_stack *a);
int *indexing(t_stack *stack);


size_t	megration_cost(t_stack *a, t_stack *b, size_t from, size_t to);


#endif
