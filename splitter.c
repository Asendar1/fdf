/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:59:15 by hassende          #+#    #+#             */
/*   Updated: 2024/10/12 18:10:47 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	splitter()
{
	int fd;
	int	ix;
	int	iy;
	int	yaxis;
	int	xaxis;
	char	*line;
	
	yaxis = 0;
	xaxis = 0;
	ix = 0;
	iy = 0;
	fd = open ("fdf.fdf", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		char **split = ft_split(line, ' ');
		iy = 0;
		while (split[iy] != NULL)
		{
			ix = 0;
			while (split[iy][ix] != '\0')
			{
				ft_printf("%c", split[iy][ix]);
				ix++;
			}
			xaxis++;
			iy++;
		}
			yaxis++;
		free(split);
		free(line);
		ft_printf("\n");
	}
	ft_printf("\n%d, %d", yaxis, xaxis/yaxis);
	close(fd);
}