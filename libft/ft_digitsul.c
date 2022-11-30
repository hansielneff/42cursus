/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitsul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:16:42 by helneff           #+#    #+#             */
/*   Updated: 2022/11/30 17:16:48 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_digitsul(unsigned long n, unsigned int base)
{
	if (n >= base)
		return (1 + ft_digitsul(n / base, base));
	else
		return (1);
}
