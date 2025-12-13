#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib.h"
# include "sort/sort.h"
# include "stack/stack.h"
# include <stdlib.h>
# include <unistd.h>

# define INVALID_INPUT 4294967295
# define MIN -2147483648
# define MAX 2147483647

int	second_step(t_stack **a, t_stack **b);
int	check_input(t_stack *a, char **args, int argc);

#endif
