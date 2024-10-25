/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:35:52 by hassende          #+#    #+#             */
/*   Updated: 2024/10/25 23:23:14 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mlx	*fdf_init(const char *FdF_file)
{
	t_mlx	*mlx;
	char	*title;
	title = ft_strjoin("FdF - ", FdF_file);
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		ft_return_error("malloc error");
	mlx->mlx = mlx_init();
	if(!mlx->mlx)
		ft_return_error("Error in mlx_init()");
	mlx->mlx_win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, title);
	if (!mlx->mlx_win)
		ft_return_error("error in mlx_win()");
	free(title);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img)
		ft_return_error("Error in mlx_new_image()");
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len, &mlx->endian);
	return (mlx);
}

static t_mapdata	*ft_map_init()
{
	t_mapdata *map;
	
	map = malloc(sizeof(t_mapdata));
	if (!map)
		ft_return_error("error initalizing map");
	map->X_axis = 0;
	map->Y_axis = 0;
	map->array = NULL;
	map->Z_axis_min = 0;
	map->Z_axis_max = 0;
	return (map);
}

void my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void dda (t_mlx *img, int x0, int y0, int x1, int y1, void *mlx, void *mlx_win)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int m = dx / dy;
	int steps = fmax(abs(dx), abs(dy));
	int i = 0;
	float xInc = (float)dx / (float)steps;
	float yInc = (float)dy / (float)steps;
	
	float x = x0;
	float y = y0;
	int color = 100000;
	while (i <= steps)
	{
		my_mlx_pixel_put(img, round(x), round(y), color);
		x += xInc;
		y += yInc;
		i++;
		color += 100000;
	}
}

int main (int argc, char *argv[])
{
	t_mlx	*mlx;
	
	if (argc == 2)
	{
		mlx = fdf_init(argv[1]);
		mlx->map = ft_map_init();
		ft_check_argv(argv[1],mlx->map);
	}
	else
		ft_return_error("Usage: ./fdf <filename>");
}
