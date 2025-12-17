/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:37:17 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/17 22:37:18 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "lib/lib.h"
# include "sort/sort.h"
# include "stack/stack.h"
# include <stdlib.h>
# include <unistd.h>

# define INVALID_INPUT 4294967295
# define MIN -2147483648
# define MAX 2147483647

# include "get_next_line/get_next_line.h"
# include "stack/stack.h"

void	p(t_stack *a, t_stack *b, char c);
void	s(t_stack *stack);
void	r(t_stack *stack);
void	rr(t_stack *stack);
void	both(t_stack *a, t_stack *b, char c);

#endif
