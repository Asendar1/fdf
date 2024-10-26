/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:38:08 by hassende          #+#    #+#             */
/*   Updated: 2024/10/26 14:01:34 by hamzah           ###   ########.fr       */
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
	free(mlx);
	exit(0);
}
