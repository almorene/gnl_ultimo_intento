/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almorene <almorene@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:03:33 by almorene          #+#    #+#             */
/*   Updated: 2024/02/16 21:17:13 by almorene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 char *read_file(char *dust, int fd)
{
	int i;
	char *buffer;

	if(fd <= 0)
		return(NULL);
	//if (!dust)
		//dust = calloc(1, 1);
	// revisar si e fd es válido
	buffer = calloc (BUFFER_SIZE + 1, sizeof(char));
		if(!buffer)
			return(NULL);
	i = 1;
	while(i != 0 && ft_compare(buffer)== 0) 
	{
		//free(buffer);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			//free(dust);
			free (buffer);
			//return (buffer = NULL, NULL);
			return(NULL);
		}
		//buffer[i] = '\0';
		dust = ft_strjoin(dust, buffer);
		free(buffer);
		//if(/*ft_strchr(buffer, '\n')*/ ft_compare(buffer) == 0)
			//break;
		//free(dust);
		//printf("%i- %s\n", i, buffer);
	}
    free(buffer);
	return(dust);
}
int main()
{
	int fd;
	static char *buffer;
	 fd = open("texto.txt", O_RDONLY);
	 //printf("%s", get_next_line(fd));
	 buffer = read_file(buffer, fd);


	 printf("%s\n", buffer);

	 return(0);
}
char *ft_getline_n(char *str)
 {
    char *str2;
    int i;
    int j;

    i = 0;
    if (!str)
        return (NULL);
    while(str[i] && str[i] != '\n')
        i++;
    str2 = (char *)calloc(sizeof(char), (i + 2));
    if(!str2)
        return(NULL);
    j = 0;
    while(str[j] != '\n' && i > j)
    {
        str2[j] = str[j];
        j++;
    }
    if(str[i] == '\n')
    {
        i++;
    }
    return(str2);
}