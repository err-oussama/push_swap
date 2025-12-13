#ifndef SORT_H
# define SORT_H

# include "../push_swap.h"
# include "push_swap.h"
#include "../stack/stack.h"

void	sort_larg_stack(t_stack *a, t_stack *b);
void	sort_small_stack(t_stack *a, t_stack *b);

void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

size_t	to_top_cost(t_stack *stack, size_t index);
size_t	to_top(t_stack *stack, size_t index, char c);

int		indexing(t_stack *stack);

#endif
