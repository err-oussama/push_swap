/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:19:07 by oerrami           #+#    #+#             */
/*   Updated: 2025/11/15 22:19:46 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*new_node(int n)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	return (node);
}

void	push(t_stack *stack, int n)
{
	t_node	*node;

	node = new_node(n);
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
		stack->size = 1;
		return ;
	}
	node->next = stack->head;
	stack->head = node;
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*node;
	int		n;

	if (stack->size == 1)
	{
		n = stack->head->n;
		free(stack->head);
		stack->tail = NULL;
		stack->head = NULL;
		stack->size--;
		return (n);
	}
	node = stack->head;
	n = stack->head->n;
	stack->head = stack->head->next;
	free(node);
	stack->size--;
	return (n);
}

void	clear(t_stack **stack)
{
	t_node	*tmp;
	t_node	*del;

	tmp = (*stack)->head;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	free(*stack);
	*stack = NULL;
}
