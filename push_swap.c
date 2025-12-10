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
		return (1);
	a = init_stack();
	b = init_stack();
	is_valid = check_input(a, &argv[1], argc - 1);
	if (is_valid)
		return (second_step(&a, &b));
	clear(&a);
	clear(&b);
	write(2, "Error\n", 6);
	return (1);
}

// 0 input => return ;
// invalid input => printf in stderr write(2, "Error\n", 6);
//
// valid input => INT_MIN < n < INT_MAX && "  +n" "  -n" "+n" "-n" " +n "
//
