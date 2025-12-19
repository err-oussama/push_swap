/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 05:13:27 by oerrami           #+#    #+#             */
/*   Updated: 2025/12/19 05:13:30 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "gnl.h"
# include "lib.h"
# include "sort.h"
# include "stack.h"
# include <stdlib.h>
# include <unistd.h>

# define INVALID_INPUT 4294967295
# define MIN -2147483648
# define MAX 2147483647

void	p(t_stack *a, t_stack *b, char c);
void	s(t_stack *stack);
void	r(t_stack *stack);
void	rr(t_stack *stack);
void	both(t_stack *a, t_stack *b, char c);

#endif
