/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:05:06 by hamzah            #+#    #+#             */
/*   Updated: 2024/10/26 16:20:21 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(int *p1, int *p2, t_mlx *mlx)
{
    int		x;
    int		y;
    int		dx;
    int		dy;
    int		sx;
    int		sy;
    int		err;
    int		e2;

    dx = abs(p2[0] - p1[0]);
    sx = p1[0] < p2[0] ? 1 : -1;
    dy = -abs(p2[1] - p1[1]);
    sy = p1[1] < p2[1] ? 1 : -1;
    err = dx + dy;
    x = p1[0];
    y = p1[1];
    while (1)
    {
        my_mlx_pixel_put(mlx, x, y, p1[1]);
        if (x == p2[0] && y == p2[1])
            break;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y += sy;
        }
    }
}