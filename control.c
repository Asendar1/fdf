/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:38:08 by hassende          #+#    #+#             */
/*   Updated: 2024/10/26 20:10:37 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
	
int close_window(void *params)
{
	t_mlx *mlx;
	int 	y;
	int 	x;

	mlx = (t_mlx *)params;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	y = -1;
	while (++y < mlx->map->Y_axis)
	{
		x = -1;
		while (++x < mlx->map->X_axis)
			free(mlx->map->array[y][x]);
		free(mlx->map->array[y]);
	}
	free(mlx->map->array);
	free(mlx->map);
	free(mlx->mlx);
	free(mlx);
	exit(0);
}

void	ft_controls(t_mlx *mlx)
{
	mlx_hook(mlx->mlx_win, 2, 1L << 0, close_window, mlx);
}