/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:58:29 by houmanso          #+#    #+#             */
/*   Updated: 2022/11/17 00:13:03 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_a_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i);
	return (-1);
}

static char	*get_the_line(char **str, char **backup, int i)
{
	char	*line;
	int		k;
	int		j;

	k = 0;
	j = 0;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (free(*str), free(*backup), NULL);
	while (k < i)
	{
		line[k] = (*str)[k];
		k++;
	}
	if ((*str)[k])
	{
		*backup = ft_calloc(ft_strlen(&str[0][k]) + 1, sizeof(char));
		if (!backup[0])
			return (free(*str), NULL);
		while ((*str)[k])
			(*backup)[j++] = (*str)[k++];
	}
	return (free(*str), line);
}

static char	*next_line(fd)
{
	static char	*backup;
	char		*buff;
	char		*str;
	int			rd;
	int			i;

	str = NULL;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	if (backup)
	{
		str = ft_strjoin(str, backup);
		free(backup);
		backup = NULL;
		if ((i = is_a_newline(str)) != -1)
			return (free(buff), get_the_line(&str, &backup, i));
	}
	rd = read(fd, buff, BUFFER_SIZE);
	while (rd > 0)
	{
		str = ft_strjoin(str, buff);
		if ((i = is_a_newline(str)) != -1)
			return (free(buff), get_the_line(&str, &backup, i));
		rd = read(fd, buff, BUFFER_SIZE);
		buff[rd] = '\0';
	}
	if (rd < 0)
		return (free(buff), free(str),free(backup) ,NULL);
	if(rd == 0)return (free(buff),free(backup), str);
	return (free(buff), str);
}

char	*get_next_line(int fd)
{
	char	*line;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (0);
	line = next_line(fd);
	return (line);
}