/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:11:36 by hamzah            #+#    #+#             */
/*   Updated: 2024/10/26 00:20:38 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_return_error(const char *err_msg)
{
	perror(err_msg);
	exit(1);
}

int	ft_hex_to_int(const char *hex_str)
{
	int	result;
	int	value;

	result = 0;
	if (hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X'))
		hex_str += 2;
	while (*hex_str)
	{
		if (ft_isdigit(*hex_str))
			value = *hex_str - '0';
		else if (*hex_str >= 'a' && *hex_str <= 'f')
			value = *hex_str - 'a' + 10;
		else if (*hex_str >= 'A' && *hex_str <= 'F')
			value = *hex_str - 'A' + 10;
		else
			break ;
		result = (result << 4) | value;
		hex_str++;
	}
	return (result);
}
