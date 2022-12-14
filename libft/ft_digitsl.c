/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitsi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:15:16 by helneff           #+#    #+#             */
/*   Updated: 2022/11/24 16:29:34 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_digitsl(long n, int base)
{
	if (n >= base || n <= -base)
		return (1 + ft_digitsl(n / base, base));
	else
		return (1);
}
