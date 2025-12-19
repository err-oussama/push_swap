/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 05:13:14 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/19 05:13:17 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_op(t_stack *a, t_stack *b, char *op)
{
	if (str_cmp(op, "pa\n"))
		p(a, b, 'a');
	if (str_cmp(op, "sa\n"))
		s(a);
	if (str_cmp(op, "ra\n"))
		r(a);
	if (str_cmp(op, "rra\n"))
		rr(a);
	if (str_cmp(op, "pb\n"))
		p(a, b, 'b');
	if (str_cmp(op, "sb\n"))
		s(b);
	if (str_cmp(op, "rb\n"))
		r(b);
	if (str_cmp(op, "rrb\n"))
		rr(b);
	if (str_cmp(op, "ss\n"))
		both(a, b, 's');
	if (str_cmp(op, "rr\n"))
		both(a, b, 'r');
	if (str_cmp(op, "rrr\n"))
		both(a, b, 'R');
}

void	execute_operation(t_stack *a, t_stack *b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		do_op(a, b, op);
		free(op);
		op = get_next_line(0);
	}
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
	{
		execute_operation(a, b);
		if (is_sorted(a) && !b->size)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	clear(&a);
	clear(&b);
	if (is_valid)
		return (0);
	return (1);
}
