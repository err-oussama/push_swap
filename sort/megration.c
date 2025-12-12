#include "sort.h"
#include <stddef.h>

size_t megration_cost(t_stack *src, t_stack * dst, size_t from, size_t to)
{
		return (to_top_cost(src,from) + insert_cost(dst, to));
}
