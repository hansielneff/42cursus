/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:13:46 by helneff           #+#    #+#             */
/*   Updated: 2023/01/16 19:08:35 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

t_stack	*create_stack(char *input[], size_t size)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->next = NULL;
	result->prev = NULL;
	result->value = ft_atoi(input[--size]);
	while (size-- > 0)
	{
		result->prev = malloc(sizeof(t_stack));
		if (!result->prev)
			return (NULL);
		result->prev->next = result;
		result = result->prev;
		result->prev = NULL;
		result->value = ft_atoi(input[size]);
	}
	return (result);
}

void	convert_stack_positional(t_stack *stack, size_t size)
{
	t_stack		*curr;
	t_stack		*smallest;
	size_t		i;
	const int	int_max = 2147483647;

	i = 0;
	while (i++ < size)
	{
		curr = stack;
		smallest = stack;
		while (curr)
		{
			if (curr->value < smallest->value)
				smallest = curr;
			curr = curr->next;
		}
		smallest->value = int_max + i;
	}
	while (stack)
	{
		stack->value -= int_max;
		stack = stack->next;
	}
}

t_stack	*index_stack(t_stack *stack, size_t index)
{
	while (index-- > 0)
		stack = stack->next;
	return (stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*next;

	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}

int	is_sorted(t_stack *stack, int reverse)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (!reverse && stack->value >= stack->next->value)
			return (0);
		if (reverse && stack->value <= stack->next->value)
			return (0);
		stack = stack->next;
	}	
	return (1);
}
