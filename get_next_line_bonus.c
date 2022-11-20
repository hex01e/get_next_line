/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:10:43 by houmanso          #+#    #+#             */
/*   Updated: 2022/11/20 21:41:22 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	is_a_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
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
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (free(*str), free(*backup), *backup = NULL, NULL);
	while (k < i)
	{
		line[k] = (*str)[k];
		k++;
	}
	line[k] = '\0';
	if (*str && (*str)[k])
	{
		*backup = malloc((ft_strlen(&(*str)[k]) + 1) * sizeof(char));
		if (!*backup)
			return (free(*str), free (line), NULL);
		while ((*str)[k])
			(*backup)[j++] = (*str)[k++];
		(*backup)[j] = '\0';
	}
	return (free(*str), line);
}

static void	get_backup(char **str, char **backup)
{
	*str = ft_strjoin(*str, *backup);
	free(*backup);
	*backup = NULL;
}

static char	*next_line(int fd, char **str, char **backup)
{
	char		*buff;
	int			rd;
	int			i;

	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (free(*backup), *backup = NULL, NULL);
	if (*backup)
		get_backup(str, backup);
	i = is_a_newline(*str);
	if (i != -1)
		return (free(buff), get_the_line(str, backup, i));
	rd = read(fd, buff, BUFFER_SIZE);
	while (rd > 0)
	{
		*str = ft_strjoin(*str, buff);
		i = is_a_newline(*str);
		if (i != -1)
			return (free(buff), get_the_line(str, backup, i));
		rd = read(fd, buff, BUFFER_SIZE);
		buff[rd] = '\0';
	}
	if (rd < 0)
		return (free(buff), free(*str), free(*backup), *backup = NULL, NULL);
	return (free(buff), *str);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*str;
	char		*line;

	str = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
	{
		if (backup[fd])
			return (free(backup[fd]), backup[fd] = NULL, NULL);
		return (NULL);
	}
	line = next_line(fd, &str, &backup[fd]);
	return (line);
}
