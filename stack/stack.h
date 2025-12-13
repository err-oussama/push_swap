/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oerrami <oerrami@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:06:04 by oerrami           #+#    #+#             */
/*   Updated: 2025/11/15 23:06:05 by oerrami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node	t_node;
struct					s_node
{
	int					value;
	size_t				index;
	t_node				*next;
};

typedef struct s_stack
{
	t_node				*head;
	t_node				*tail;
	size_t				size;
}						t_stack;

t_stack					*init_stack(void);
t_node					*new_node(int n);

void					push(t_stack *stack, t_node *node);
void					clear(t_stack **stack);
t_node					*pop(t_stack *stack);
int						is_sorted(t_stack *stack);
int						search(t_stack *stack, int n);

int						get_index(t_stack *stack, size_t index);
int						get_min(t_stack *stack);

void					swap(t_stack *stack, char c);
void					rotate(t_stack *stack, char c);
void					rev_rotate(t_stack *stack, char c);
void					push_op(t_stack *a, t_stack *b, char c);

#endif
