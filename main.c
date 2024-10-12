/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:35:52 by hassende          #+#    #+#             */
/*   Updated: 2024/10/12 17:14:25 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main ()
{
	void *mlx;
	void *mlx_win;
	int	x = 200;
	int	y = 200;
	splitter();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 860, 430, "Hello world");
	while (y != 300)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 1000);
		// x++;
		y++;
	}
	x = 200;
	while (x != 500)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 13251231);
		x++;
	}
	while(y != 200)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 6624303);
		y--;
	}
	while(x != 200)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 16777215);
		x--;
	}
	mlx_loop(mlx);

	return (0);
}