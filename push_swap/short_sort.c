/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:57:42 by helneff           #+#    #+#             */
/*   Updated: 2023/01/17 18:47:29 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "short_sort.h"
#include "instructions.h"
#include "solutions.h"

static void	free_nops(t_list **instructions, t_list **curr, t_list **prev)
{
	if (!*prev)
	{
		*instructions = (*curr)->next->next;
		ft_lstdelone((*curr)->next, free_solution);
		ft_lstdelone(*curr, free_solution);
		*curr = *instructions;
	}
	else
	{
		(*prev)->next = (*curr)->next->next;
		ft_lstdelone((*curr)->next, free_solution);
		ft_lstdelone(*curr, free_solution);
		*curr = (*prev)->next;
	}
}

static int	remove_nop_rotations(t_list **instructions)
{
	int		found_nops;
	t_list	*curr;
	t_list	*prev;

	found_nops = 0;
	curr = *instructions;
	prev = NULL;
	while (curr->next)
	{
		if ((!ft_strncmp(curr->content, "ra", 2)
				&& !ft_strncmp(curr->next->content, "rra", 3))
			|| (!ft_strncmp(curr->content, "rra", 3)
				&& !ft_strncmp(curr->next->content, "ra", 2)))
		{
			free_nops(instructions, &curr, &prev);
			found_nops = 1;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
	return (found_nops);
}

static void	merge_b(t_stack **a, t_stack **b, t_list **instructions)
{
	t_stack	*a_last;

	while (*b)
	{
		a_last = *a;
		while (a_last->next)
			a_last = a_last->next;
		if ((*b)->next && (*b)->value == 5 && (*b)->next->value == 4)
			swap(*b, 'b', instructions);
		if ((*b)->value > a_last->value)
		{
			push(b, a, 'a', instructions);
			rot(a, 'a', instructions);
		}
		else
		{
			while ((*b)->value > (*a)->value)
				rot(a, 'a', instructions);
			push(b, a, 'a', instructions);
			while (!is_sorted(*a, 0))
				rrot(a, 'a', instructions);
		}
	}
}

static void	sort_three(t_stack **a, t_list **instructions)
{
	const int	first = (*a)->value;
	const int	second = (*a)->next->value;
	const int	third = (*a)->next->next->value;

	if (first < second && third < second && first < third)
	{
		swap(*a, 'a', instructions);
		rot(a, 'a', instructions);
	}
	else if (first < third && second < third && second < first)
		swap(*a, 'a', instructions);
	else if (first < second && third < second && third < first)
		rrot(a, 'a', instructions);
	else if (second < first && third < first && second < third)
		rot(a, 'a', instructions);
	else if (second < first && third < first && third < second)
	{
		swap(*a, 'a', instructions);
		rrot(a, 'a', instructions);
	}
}

t_list	*short_sort(t_stack **a, t_stack *b, size_t size)
{
	t_list	*instructions;

	instructions = NULL;
	if (size == 2)
	{
		swap(*a, 'a', &instructions);
		return (instructions);
	}
	while (size-- > 3)
		push(a, &b, 'b', &instructions);
	sort_three(a, &instructions);
	merge_b(a, &b, &instructions);
	while (remove_nop_rotations(&instructions))
		;
	return (instructions);
}
