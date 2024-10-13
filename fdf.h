/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:31:22 by hassende          #+#    #+#             */
/*   Updated: 2024/10/13 16:40:27 by hassende         ###   ########.fr       */
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
#include "gnl/get_next_line_bonus.h"
#include "libft/libft.h"
#include "ft_printf/includes/ft_printf.h"

typedef struct pixel_data 
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				p_data;

typedef struct fdf
{
	int x;
	int y;
	int z;
}	 		fdf;

void	splitter(fdf *cords);


#endif