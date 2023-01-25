/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:01:25 by helneff           #+#    #+#             */
/*   Updated: 2023/01/16 19:08:44 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	long			value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

t_stack	*create_stack(char *input[], size_t size);
void	convert_stack_positional(t_stack *stack, size_t size);
t_stack	*index_stack(t_stack *stack, size_t index);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack, int reverse);

#endif
