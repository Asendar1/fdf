/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzah <hamzah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:12:57 by hassende          #+#    #+#             */
/*   Updated: 2024/10/26 13:43:08 by hamzah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
// size_t	fft_strlen(const char *s);
// char	*ft_strdup(const char *s);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strchr(const char *s, int c);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif