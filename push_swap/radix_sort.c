/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:22:47 by helneff           #+#    #+#             */
/*   Updated: 2023/01/25 09:43:31 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "radix_sort.h"
#include "instructions.h"

static int	iterate_stack_a(
	t_stack **a, t_stack **b, int bit_shift, t_list **instructions)
{
	size_t	b_increment;

	b_increment = 0;
	if (is_sorted(*a, 0) && is_sorted(*b, 1))
		return (b_increment);
	else if (((*a)->value >> bit_shift) & 0b1)
		rot(a, 'a', instructions);
	else
	{
		push(a, b, 'b', instructions);
		++b_increment;
	}
	return (b_increment);
}

static int	iterate_stack_b(
	t_stack **a, t_stack **b, int bit_shift, t_list **instructions)
{
	size_t	a_increment;

	a_increment = 0;
	if (((*b)->value >> (bit_shift + 1)) & 0b1
		|| (is_sorted(*a, 0) && is_sorted(*b, 1)))
	{
		push(b, a, 'a', instructions);
		++a_increment;
	}
	else
		rot(b, 'b', instructions);
	return (a_increment);
}

t_list	*radix_sort(t_stack **a, t_stack *b, size_t size)
{
	t_list	*instructions;
	int		bit_shift;
	size_t	a_size;
	size_t	b_size;

	instructions = NULL;
	bit_shift = 0;
	a_size = size;
	b_size = 0;
	while (!is_sorted(*a, 0) || b)
	{
		while (a_size-- > 0)
			b_size += iterate_stack_a(a, &b, bit_shift, &instructions);
		a_size = size - b_size;
		while (b_size-- > 0)
			a_size += iterate_stack_b(a, &b, bit_shift, &instructions);
		b_size = size - a_size;
		++bit_shift;
	}
	return (instructions);
}
