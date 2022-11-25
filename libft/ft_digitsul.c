/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitsul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:15:16 by helneff           #+#    #+#             */
/*   Updated: 2022/11/16 08:46:18 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_digitsul(unsigned long n, unsigned int base)
{
	if (n >= base)
		return (1 + ft_digitsul(n / base, base));
	else
		return (1);
}
