/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 05:16:49 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/19 05:16:50 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"
# include "stack.h"

void	sort(t_stack *a, t_stack *b);

void	sort_larg_stack(t_stack *a, t_stack *b);
void	sort_small_stack(t_stack *a, t_stack *b);

void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

void	to_top(t_stack *stack, size_t index, char c);

int		indexing(t_stack *stack);

#endif
