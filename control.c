/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:38:08 by hassende          #+#    #+#             */
/*   Updated: 2024/10/20 14:30:17 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int close_window(int keycode, void *mlx, void *mlx_win)
{
	mlx_destroy_window(mlx, mlx_win);
	return (0);
}
