/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:15:24 by hamzah            #+#    #+#             */
/*   Updated: 2024/10/27 15:02:37 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_mapdata *map, t_mlx *mlx)
{
	int		x;
	int		y;

	//ft_bzero(mlx->addr, WIDTH * HEIGHT * (mlx->bpp / 8));
	y = 0;
	while (y < map->Y_axis && y >= 0)
	{
		x = 0;
		while (x < map->X_axis && x >= 0)
		{
			if (x + 1 < map->X_axis)
			{
				ft_printf("x_atcall: %d, y_atcall: %d\n", map->array[y][x], map->array[y][x + 1]);
				ft_draw_line(map->array[y][x], map->array[y][x + 1], mlx);
			}
			if (y + 1 < map->Y_axis)
			{
				// ft_printf("x_atcall: %d, y_atcall: %d\n", map->array[y][x], map->array[y + 1][x]);
				ft_draw_line(map->array[y][x], map->array[y + 1][x], mlx);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);	
}
