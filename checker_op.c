/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:38:07 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/17 22:38:08 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	p(t_stack *a, t_stack *b, char c)
{
	if (c == 'a')
		push(a, pop(b));
	else if (c == 'b')
		push(b, pop(a));
}

void	s(t_stack *stack)
{
	int	tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
}

void	r(t_stack *stack)
{
	t_node	*node;

	if (stack->size <= 1)
		return ;
	node = stack->head;
	stack->head = stack->head->next;
	stack->tail->next = node;
	node->next = NULL;
	stack->tail = node;
}

void	rr(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->head;
	while (tmp->next != stack->tail)
		tmp = tmp->next;
	tmp->next = NULL;
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	stack->tail = tmp;
}

void	both(t_stack *a, t_stack *b, char c)
{
	if (c == 's')
	{
		s(a);
		s(b);
	}
	else if (c == 'r')
	{
		r(a);
		r(b);
	}
	else if (c == 'R')
	{
		rr(a);
		rr(b);
	}
}
