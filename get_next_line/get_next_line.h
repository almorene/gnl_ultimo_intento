/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almorene <almorene@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:03:00 by almorene          #+#    #+#             */
/*   Updated: 2024/02/16 21:30:18 by almorene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

int     ft_compare(char *str);
char    *ft_get_line_n(char *str);
char	*ft_strchr(const char *s, int c);
int	    ft_strlen(const char *src);
//char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin(char *left_str, char *buff);
char    *read_file(char *dust, int fd);
char    *next_line(char *buffer);
char    *get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);


#endif