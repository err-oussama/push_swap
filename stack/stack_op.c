/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 03:27:53 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/10 03:28:03 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push_op(t_stack *a, t_stack *b, char c)
{
	char op[3];

	if (c == 'a')
		push(a, pop(b));
	else if (c == 'b')
		push(b, pop(a));
	op[0] = 'p';
	op[1] = c;
	op[2] = '\n';
	write(1, op,3);
}

void	swap(t_stack *stack, char c)
{
	int	tmp;
	char	op[3];

	if (stack->size <= 1)
		return ;
	tmp = stack->head->n;
	stack->head->n = stack->head->next->n;
	stack->head->next->n = tmp;
	op[0] = 's';
	op[1] = c;
	op[2] = '\n';
	write(1, op,3);
}

void	rotate(t_stack *stack, char c)
{
	t_node	*node;
	char op[3];

	if (stack->size <= 1)
		return ;
	node = stack->head;
	stack->head = stack->head->next;
	stack->tail->next = node;
	node->next = NULL;
    stack->tail = node;
    op[0] = 'r';
	op[1] = c;
	op[2] = '\n';
	write(1, op,3);
}

void	rev_rotate(t_stack *stack, char c)
{
	t_node	*tmp;
	char	op[4];

	if (stack->size <= 1)
		return ;
	tmp = stack->head;
	while (tmp->next != stack->tail)
		tmp = tmp->next;
	tmp->next = NULL;
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	stack->tail = tmp;
	op[0] = 'r';
	op[1] = 'r';
	op[2] = c;
	op[3] = '\n';
	write(1, op, 4);
}
