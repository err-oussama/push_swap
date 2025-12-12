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
		if (tmp->n == n)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}



int get_pos_dec(t_stack *stack, int n)
{
    t_node *tmp;
    int i;

    if (n > stack->head->n)
        return (0);
    if (n < stack->tail->n)
        return (stack->size);
    i = 0;
    tmp = stack->head;
    while (tmp->next)
    {
        if (tmp->n > n && n > tmp->next->n)
            return (i + 1);
        i++;
        tmp = tmp->next;
    }
    return (i);
}

int get_pos_inc(t_stack *stack, int n)
{
    t_node *tmp;
    int i;

    if (n < stack->head->n)
        return (0);
    if (n > stack->tail->n)
        return (stack->size);
    i = 0;
    tmp = stack->head;
    while (tmp->next)
    {
        if (tmp->n < n && n < tmp->next->n)
            return (i + 1);
        i++;
        tmp = tmp->next;
    }
    return (i);
}

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return (1);
	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}



void display(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->head;
    printf("\n\n");
    while (tmp)
	{
		printf("%i\n", tmp->n);
		tmp = tmp->next;
	}
    printf("\n\n");
}

