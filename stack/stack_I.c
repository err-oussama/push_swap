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

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	push(t_stack *stack, t_node *node)
{
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

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 1)
	{
		node = stack->head;
		stack->tail = NULL;
		stack->head = NULL;
		stack->size--;
		node->next = NULL;
		return (node);
	}
	node = stack->head;
	stack->head = stack->head->next;
	stack->size--;
	node->next = NULL;
	return (node);
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
