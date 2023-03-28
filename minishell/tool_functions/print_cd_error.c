/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cd_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:48:00 by tpoho             #+#    #+#             */
/*   Updated: 2023/03/21 13:50:05 by tpoho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	print_cd_error(char *string)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(string, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}
