/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almorene <almorene@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:53:53 by almorene          #+#    #+#             */
/*   Updated: 2024/02/16 22:08:06 by almorene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
        str2[j] = '\n';
    }
    return(str2);
}
/*int main()
 {
    char *str = "hola que tal\n";
    char *str2 = "hhh\nhh";
    char *str3 = NULL;
    char *sol;
    char *sol2;
    char *sol3;
    int a = 0;
    int b = 0;


    //a =boolean(str);
    //b = boolean(str2);

    //printf("%d\n", a);
    //printf("%d\n", b);

   sol = ft_getline_n(str);
  //printf("After first\n");
 sol2 = ft_getline_n(str2);
  //printf("After second\n");
 sol3 = ft_getline_n(str3);
  //printf("After last\n");

   printf("%s\n", sol);
   printf("After first\n");
   printf("%s\n", sol2);
   printf("After second\n");
   printf("%s\n", sol3);
    return(0);
 }*/
 char *read_file(char *dust, int fd)
{
	int i;
	char *buffer;

	//if(fd <= 0)
		//return(NULL);
	//if (!dust)
		//dust = calloc(1, 1);
	// revisar si e fd es válido
	buffer = calloc (BUFFER_SIZE + 1, sizeof(char));
		if(!buffer)
			return(NULL);
	i = 1;
	while(i > 0 && ft_compare(buffer)== 0) //!ft_strchr(dust, '\n') ) 
	{
		//free(buffer);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(dust);
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
	return(dust);
}
/*int main()
{
	int fd;
	static char *buffer;
	 fd = open("texto.txt", O_RDONLY);
	 //printf("%s", get_next_line(fd));
	 buffer = read_file(buffer, fd);


	 printf("%s\n", buffer);

	 return(0);
}*/
/*char *next_line(char *buffer)
{
	int i;
	int j;
	int k;
	int h;
	char *line_ob;

	i = 0;
	j = 0;
	if(!buffer)
		return(NULL);
	i = ft_strlen(buffer);
	while (buffer[j] && buffer[j] != '\n')
		j++;
	if(!buffer[j])
	{
		free(buffer);
		return (NULL);
	}
	while(buffer[j] == '\n')
		j++;
	k = i - j;
	//printf("%d\n", k);
	line_ob = (char *)malloc(sizeof(char) * k + 1);
	if(!line_ob)
		return(NULL);
	//printf("%d\n", j);
	h = 0;
	while(buffer[k])
	{
		line_ob[h++] = buffer[k++];
	}
	line_ob[i] = '\0';
	return(line_ob);
}*/
char *next_line(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	str = (char *)calloc(sizeof(char),(ft_strlen(buffer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	free(buffer);
	return (str);
}


/*int main()
{
	char *buf = "hola\n uuuu";

	char *line;

	line = next_line(buf);

	printf("%s\n", line);

	return(0);
}*/
char *get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_file(save, fd);
	if (!save)
	{
		return (NULL);
	}
	line = ft_getline_n(save);
	save = next_line(save);
	return (line);

}

int main()
{
	int fd;
	char *line;
	int i = 0;
	
	fd = open("texto.txt", O_RDONLY);
	/*while (i < 3)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
		i++;
	}*/
	line = get_next_line(fd);
	printf("%s\n", line);
	return(0);

}
