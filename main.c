/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:35:52 by hassende          #+#    #+#             */
/*   Updated: 2024/10/13 17:47:02 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_pixel_put(p_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void dda (p_data *img, int x0, int y0, int x1, int y1, void *mlx, void *mlx_win)
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
	while (i <= steps)
	{
		my_mlx_pixel_put(img, round(x), round(y), 0xFFFFFF);
		x += xInc;
		y += yInc;
		i++;
	}
}


int main ()
{
	void *mlx;
	void *mlx_win;
	p_data	img;
	fdf	cords;

	int	x0 = 200;
	int	y0 = 200;
	int x1 = 500;
	int y1 = 300;
	
	splitter(&cords);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "DDA");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	dda(&img, x0, y0, x1, y1, mlx, mlx_win);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	

	return (0);
}