/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:54:25 by helneff           #+#    #+#             */
/*   Updated: 2023/01/05 10:44:19 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

static void	add_instruction(
	t_list	**instructions, char	*inst, char letter)
{
	char	*prev_inst;
	t_list	*last_node;
	size_t	inst_len;

	inst_len = ft_strlen(inst);
	if (*instructions)
	{
		last_node = ft_lstlast(*instructions);
		prev_inst = last_node->content;
		if (*inst != 'p' && !ft_strncmp(prev_inst, inst, inst_len)
			&& prev_inst[inst_len] != prev_inst[0]
			&& prev_inst[inst_len] != letter
			&& prev_inst[inst_len] != '\0')
		{
			free(last_node->content);
			last_node->content = ft_strpad(inst, inst[0], 1, 1);
			return ;
		}
	}
	ft_lstadd_back(instructions, ft_lstnew(ft_strpad(inst, letter, 1, 1)));
}

void	swap(t_stack *stack, char letter, t_list **instructions)
{
	t_stack		*first_elem;
	int			first_value;

	if (!stack || !stack->next)
		return ;
	first_elem = stack;
	first_value = stack->value;
	stack = stack->next;
	first_elem->value = stack->value;
	stack->value = first_value;
	add_instruction(instructions, "s", letter);
}

void	push(t_stack **from, t_stack **to, char letter, t_list **instructions)
{
	t_stack		*a_first;

	if (!*from)
		return ;
	a_first = *from;
	*from = a_first->next;
	a_first->next = NULL;
	if (*from)
		(*from)->prev = NULL;
	if (!*to)
		*to = a_first;
	else
	{
		(*to)->prev = a_first;
		a_first->next = *to;
		*to = a_first;
	}
	add_instruction(instructions, "p", letter);
}

void	rot(t_stack **stack, char letter, t_list **instructions)
{
	t_stack		*first_elem;
	t_stack		*last_elem;

	if (!*stack || !(*stack)->next)
		return ;
	first_elem = *stack;
	*stack = (*stack)->next;
	first_elem->next = NULL;
	(*stack)->prev = NULL;
	last_elem = *stack;
	while (last_elem->next)
		last_elem = last_elem->next;
	last_elem->next = first_elem;
	first_elem->prev = last_elem;
	add_instruction(instructions, "r", letter);
}

void	rrot(t_stack **stack, char letter, t_list **instructions)
{
	t_stack		*last_elem;

	if (!*stack || !(*stack)->next)
		return ;
	last_elem = *stack;
	while (last_elem->next)
		last_elem = last_elem->next;
	last_elem->prev->next = NULL;
	last_elem->next = *stack;
	(*stack)->prev = last_elem;
	*stack = last_elem;
	add_instruction(instructions, "rr", letter);
}
