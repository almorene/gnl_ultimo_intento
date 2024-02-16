/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almorene <almorene@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:05:30 by almorene          #+#    #+#             */
/*   Updated: 2024/02/16 21:29:45 by almorene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int ft_compare(char *str)
 {
    int flag;
    int i;

    flag = 0;
    i = 0;
    while(str[i] != '\0')
    {
        if (str[i] == '\n')
         flag = 1;
        i++; 
    }
	// printf("-------FLAG = %i ------\n", flag);
    return(flag);
 }

 int	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

 /*char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;
	int		i2;

	if (!s1)
		s1 = malloc(sizeof(char) * 1);
	if (!s1)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str || !s2 || !s1)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	i2 = 0;
	while (s2[i2] != '\0')
		str[i++] = s2 [i2++];
	str[i] = '\0';
	return (str);
}*/
char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char ) c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char )c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *) src;
	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}