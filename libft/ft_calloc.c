/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:41:36 by helneff           #+#    #+#             */
/*   Updated: 2022/11/18 09:35:27 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*allocation;
	size_t	size;

	size = nelem * elsize;
	if (!nelem || !elsize || size / nelem != elsize)
		return (calloc(1, 1));
	allocation = malloc(size);
	if (allocation != NULL)
		ft_bzero(allocation, size);
	return (allocation);
}
