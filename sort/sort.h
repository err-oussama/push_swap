/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:36:58 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/17 22:37:00 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../push_swap.h"
# include "../stack/stack.h"
# include "push_swap.h"

void	sort(t_stack *a, t_stack *b);

void	sort_larg_stack(t_stack *a, t_stack *b);
void	sort_small_stack(t_stack *a, t_stack *b);

void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

void	to_top(t_stack *stack, size_t index, char c);

int		indexing(t_stack *stack);

#endif
