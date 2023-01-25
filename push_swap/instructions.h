/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:54:38 by helneff           #+#    #+#             */
/*   Updated: 2022/12/16 07:52:03 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "libft.h"
# include "stack.h"

void	swap(t_stack *stack, char letter, t_list **instructions);
void	push(t_stack **from, t_stack **to, char letter, t_list **instructions);
void	rot(t_stack **stack, char letter, t_list **instructions);
void	rrot(t_stack **stack, char letter, t_list **instructions);

#endif
