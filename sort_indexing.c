/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_indexing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 05:17:08 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/19 05:17:09 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	sort_array(int *arr, size_t size)
{
	size_t	i;
	size_t	j;
	int		t;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}

static void	fill_sort_array(int *arr, t_stack *a)
{
	t_node	*tmp;
	int		i;

	tmp = a->head;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_array(arr, a->size);
}

int	indexing(t_stack *stack)
{
	t_node	*tmp;
	size_t	i;
	int		*arr;

	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (0);
	fill_sort_array(arr, stack);
	tmp = stack->head;
	while (tmp)
	{
		i = -1;
		while (++i < stack->size)
			if (arr[i] == tmp->value)
				tmp->index = i;
		tmp = tmp->next;
	}
	free(arr);
	return (1);
}
