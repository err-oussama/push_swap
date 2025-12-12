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

# include <stdio.h> 
# include <unistd.h>

typedef struct s_node	t_node;
struct					s_node
{
	int					n;
	t_node				*next;
};

typedef struct s_stack
{
	t_node				*head;
	t_node				*tail;
	size_t				size;
}						t_stack;



void display(t_stack *stack);

t_stack					*init_stack(void);
t_node					*new_node(int n);

void					push(t_stack *stack, int n);
int						pop(t_stack *stack);
void					clear(t_stack **stack);
int						search(t_stack *stack, int n);
int						is_sorted(t_stack *stack);


int get_pos_inc(t_stack *stack, int n);
int get_pos_dec(t_stack *stack, int n);


int						get_index_min(t_stack stack);

//						stack operation
void					swap(t_stack *stack, char c);
void					rotate(t_stack *stack, char c);
void					rev_rotate(t_stack *stack, char c);
void					push_op(t_stack *a, t_stack *b, char c);

#endif
