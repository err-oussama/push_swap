/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:38:15 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/17 22:38:16 by oerrami          ###   ########.fr       */
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
			push(a, new_node((int)n));
		}
		free(array);
	}
	return (1);
}
