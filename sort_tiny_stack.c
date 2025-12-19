/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 05:17:18 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/19 05:17:19 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_3(t_stack *a)
{
	if (a->head->next->value > a->head->value
		&& a->head->next->value > a->tail->value)
		rev_rotate(a, 'a');
	else if (a->head->value > a->head->next->value
		&& a->head->value > a->tail->value)
		rotate(a, 'a');
	if (a->head->next->value < a->head->value)
		swap(a, 'a');
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	index;

	index = search(a, get_min(a));
	if (index == 1)
		swap(a, 'a');
	else if (index == 3)
		rev_rotate(a, 'a');
	else if (index == 2)
	{
		rev_rotate(a, 'a');
		rev_rotate(a, 'a');
	}
	push_op(a, b, 'b');
	sort_3(a);
	push_op(a, b, 'a');
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	index;

	index = search(a, get_min(a));
	if (index == 1)
		swap(a, 'a');
	else if (index == 4)
		rev_rotate(a, 'a');
	else if (index == 3 || index == 2)
		while (index++ < 5)
			rev_rotate(a, 'a');
	push_op(a, b, 'b');
	sort_4(a, b);
	push_op(a, b, 'a');
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		return (swap(a, 'a'));
	if (a->size == 3)
		return (sort_3(a));
	if (a->size == 4)
		return (sort_4(a, b));
	if (a->size == 5)
		return (sort_5(a, b));
	sort_larg_stack(a, b);
}
