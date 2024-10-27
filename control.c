/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:38:08 by hassende          #+#    #+#             */
/*   Updated: 2024/10/27 11:45:37 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
	
int close_window(t_mlx *mlx)
{
	int 	y;
	int 	x;

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

int	key_down_hook(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		close_window(mlx);
	return (0);
}

void	ft_controls(t_mlx *mlx)
{
	mlx_hook(mlx->mlx_win, 2, 1L << 0, key_down_hook, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, close_window, mlx);
}