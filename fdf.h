/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:31:22 by hassende          #+#    #+#             */
/*   Updated: 2024/10/27 11:42:21 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <X11/keysym.h>

#include "gnl/get_next_line_bonus.h"
#include "libft/libft.h"
#include "ft_printf/includes/ft_printf.h"

#define WIDTH 1920
#define HEIGHT 1080


# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define MINUS 27
# define PLUS 24
# define SPACE 49
# define KEY_R 15
# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_CLICK_MIDDLE 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define ESCAPE 53

typedef struct s_mapdata
{
	int	X_axis;
	int	Y_axis;
	int	***array;
	int	Z_axis_min;
	int	Z_axis_max;
}	 		t_mapdata;

typedef struct s_mlx
{
	void 	*mlx;
	void 	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_mapdata *map;
}		t_mlx;

void	ft_check_argv(char *filename, t_mapdata *map);
void    ft_return_error(const char *err_msg);
int 	ft_hex_to_int(const char *hex_str);
int 	close_window(t_mlx *mlx);
void	ft_draw_line(int *p1, int *p2, t_mlx *mlx);
void	ft_draw(t_mapdata *map, t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void	ft_controls(t_mlx *mlx);


#endif