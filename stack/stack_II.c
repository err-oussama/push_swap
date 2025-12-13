/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 03:04:01 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/06 03:04:04 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stddef.h>

int	search(t_stack *stack, int n)
{
	t_node	*tmp;
	int	i;

	i = 0;
	if (!stack->size)
		return (-1);
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->value == n)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}


int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return (1);
	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_index(t_stack *stack, size_t index)
{
	t_node *tmp;
	size_t i;

	i = 0;
	tmp = stack->head;
    while (tmp && i++ < index)
		tmp = tmp->next;
	return (tmp->value);
}

int get_min(t_stack *stack)
{
    t_node* tmp;
    int min;

    tmp = stack->head;
    min = tmp->value;
    while (tmp)
    {
        if (tmp->value < min)
            min = tmp->value;
        tmp = tmp->next;
    }
    return (min);
}
