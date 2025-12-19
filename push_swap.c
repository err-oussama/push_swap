/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 05:16:21 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/19 05:16:23 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		if (!is_sorted(a))
			sort(a, b);
	}
	clear(&a);
	clear(&b);
	if (is_valid)
		return (0);
	return (1);
}
