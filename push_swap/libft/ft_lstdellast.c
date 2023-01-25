/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:00:02 by helneff           #+#    #+#             */
/*   Updated: 2022/12/07 17:18:19 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdellast(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*prev;

	if (lst == NULL || del == NULL)
		return ;
	curr = *lst;
	prev = NULL;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	if (curr->content != NULL)
		del(curr->content);
	free(curr);
	*lst = prev;
	if (prev)
		prev->next = NULL;
}
