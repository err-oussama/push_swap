#include "sort.h"

void	sort_larg_stack(t_stack *a, t_stack *b, int *arr)
{
    push_op(a,b, 'b');
    while(a->size > 5)
        insert(a, b, get_pos_dec(b,a->head->n), 'b');
    sort_5(a, b, arr);
    while (b->size)
        insert(a, b, get_pos_inc(a, b->head->n), 'a');

}
