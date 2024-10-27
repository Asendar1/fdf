/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:05:06 by hamzah            #+#    #+#             */
/*   Updated: 2024/10/27 15:01:47 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(int *p1, int *p2, t_mlx *mlx)
{
    int dx, dy, steps;
    float x_increment, y_increment;
    float x, y;

	printf("p1: x: %d, y: %d\n", p1[0], p1[1]);
    dx = p2[0] - p1[0];
    dy = p2[1] - p1[1];

    printf("dx: %d, dy: %d\n", dx, dy);

    if (dx == 0 && dy == 0) {
        // If both dx and dy are zero, draw a single point
        my_mlx_pixel_put(mlx, p1[0] + 100, p1[1] + 100, 0xff0000);
        printf("Single point at x: %d, y: %d\n", p1[0], p1[1]);
        return;
    }

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    printf("steps: %d\n", steps);

    x_increment = (float)dx / (float)steps;
    y_increment = (float)dy / (float)steps;

    printf("x_increment: %f, y_increment: %f\n", x_increment, y_increment);

    x = (float)p1[0];
    y = (float)p1[1];

    printf("Initial x: %f, Initial y: %f\n", x, y);

    int i = 0;
    while (i <= steps)
    {
        my_mlx_pixel_put(mlx, round(x + 100), round(y + 100), 0xff0000);
        x += x_increment;
        y += y_increment;
        i++;
    }
}