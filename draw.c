/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:15:24 by hamzah            #+#    #+#             */
/*   Updated: 2024/10/26 16:06:22 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_mapdata *map, t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->Y_axis && y >= 0)
	{
		x = 0;
		while (x < map->X_axis && x >= 0)
		{
			if (x + 1 < map->X_axis)
				ft_draw_line(map->array[y][x], map->array[y][x + 1], mlx);
			if (y + 1 < map->Y_axis)
				ft_draw_line(map->array[y][x], map->array[y + 1][x], mlx);
			x++;
		}
		y++;
	}
	
}