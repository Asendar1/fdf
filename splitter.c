/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassende <hassende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:59:15 by hassende          #+#    #+#             */
/*   Updated: 2024/10/13 17:19:20 by hassende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	splitter(fdf *cords)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**parse;
	
	cords->x = 0;
	cords->y = 0;
	
	fd = open("fdf.fdf", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL) {
        parse = ft_split(line, ' ');
        if (parse == NULL) {
            free(line);
            continue;
        }

        i = 0;
        while (parse[i] != NULL) {
            cords->x++;
            free(parse[i]);
            i++;
        }
        free(parse);
        free(line);
        cords->y++;
    }
	close(fd);
	printf("\ncolumns = %d, rows = %d\n", cords->x / cords->y, cords->y );
}