/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:59:15 by hassende          #+#    #+#             */
/*   Updated: 2024/10/26 00:12:36 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int ft_get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error");
	height = 0;
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

static int	ft_get_width(char *filename)
{
	int		fd;
	int		width;
	int		i;
	char	*line;
	
	fd = open (filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error");
	width = 0;
	line = get_next_line(fd);
	if (!line || *line == '\0')
	{
		free(line);
		ft_return_error("invalid map (empty)");
	}
	while (line[++i])
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
	free(line);
	close(fd);
	return (width);
}

static void ft_fill_table(int **array, char *line, int width)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(line, ' ');
	i = -1;
	while(split[++i] && i < width)
	{
		array[i] = malloc(sizeof(int) * 2);
		if(!array[i])
			ft_return_error("malloc error");
		array[i][0] = ft_atoi(split[i]);
		j = 0;
		while (split[i][j] && split[i][j] != ',')
			j++;
		if (split[i][j] == ',')
			array[i][1] = ft_hex_to_int(split[i] + j + 1);
		else
			array[i][1] = -1;
		free(split[i]);
	}
	if (i != width || split[i])
		ft_return_error("error: fdf file in incorrect");
	free(split[i]);
}

void	ft_check_argv(char *filename, t_mapdata *map)
{
	int		fd;
	int		i;
	char	*line;

	map->X_axis = (ft_get_width(filename));
	map->Y_axis = (ft_get_height(filename));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error");
	i = -1;
	map->array = malloc(sizeof(int **) * map->Y_axis);
	if (!map->array)
		ft_return_error("malloc error");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map->array[++i] = malloc(sizeof(int *) * map->X_axis);
		if (!map->array[i])
			ft_return_error("malloc error");
		ft_fill_table(map->array[i], line, map->X_axis);
		free(line);
	}
	ft_get_z_min_man(map);
	close(fd);
}