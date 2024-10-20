/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:59:15 by hassende          #+#    #+#             */
/*   Updated: 2024/10/20 14:48:17 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parser(fdf *cords)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**parse;
	
	cords->x = 0;
	cords->y = 0;
	
	fd = open("fdf.fdf", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
    {
		ft_atoi(line)
	}
	close(fd);
	printf("\ncolumns = %d, rows = %d\n", cords->x / cords->y, cords->y );
}