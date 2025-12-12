/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:44:42 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/05 00:44:44 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort/sort.h"
#include "stack/stack.h"


void sort(t_stack *a, t_stack *b)
{
    t_sorted_array	arr;

	if (a->size == 2)
		return (swap(a, 'a'));
	if (a->size == 3)
		return (sort_3(a));
	arr.size = a->size;
	arr.arr = c_alloc(a->size, sizeof(int));
	if (!arr.arr)
		return ;
	fill_sort_array(&arr, a);
	if (a->size == 4)
		return (sort_4(a, b, arr.arr));
	if (a->size == 5)
		return (sort_5(a,b,arr.arr));
    sort_larg_stack(a,b, arr.arr);
    free(arr.arr);
}
int	check_input(t_stack *a, char **args, int argc)
{
	char	**array;
	long	n;
	size_t	i;

	while (argc--)
	{
		array = split(args[argc], &i);
		if (!array)
			return (0);
		while (i--)
		{
			n = a_to_l(array[i]);
			free(array[i]);
			if (n == INVALID_INPUT || search(a, (int)n) != -1)
				return (clear_array(array, i));
			push(a, (int)n);
		}
		free(array);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		is_valid;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = init_stack();
	b = init_stack();
	is_valid = check_input(a, &argv[1], argc - 1);
	if (!is_valid)
        write(2, "Error\n", 6);
    else
        if (!is_sorted(a))
            sort(a, b);
    clear(&a);
	clear(&b);

	return (1);
}
