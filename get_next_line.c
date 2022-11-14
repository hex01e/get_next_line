/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:58:29 by houmanso          #+#    #+#             */
/*   Updated: 2022/11/14 16:15:05 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

static int	is_new_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		if (str[i++] == '\n')
			return (i);
	return (-1);
}

static char	*get_the_line(char *str, char **res, int i)
{
	char *s;
	*res = ft_substr(str , i, ft_strlen(str));
	s = ft_substr(str, 0, i);
	return(s);
}

char *get_next_line(int fd)
{
	char		*buff;
	char		*str;
	static char	*res;
	int			rd;
	int			i;

	str = NULL;
	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	rd = read(fd, buff, BUFFER_SIZE);
	while (rd > 0)
	{
		if (res)
			str = ft_strjoin(str, res);
		str = ft_strjoin(str, buff);
		i = is_new_line(str);
		if (i != -1)
			return (free(buff), get_the_line(str, &res, i));
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		rd = read(fd, buff, BUFFER_SIZE);
		buff[rd] = '\0';
	}
	free(buff);
	return (str);
}
