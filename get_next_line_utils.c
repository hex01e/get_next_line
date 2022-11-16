/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:44:35 by houmanso          #+#    #+#             */
/*   Updated: 2022/11/16 19:07:08 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = malloc(count * size);
	if (!p)
		return (NULL);
	while (i < (count * size))
		p[i++] = 0;
	return (p);
}

char	*ft_strdup(char *s1)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	newstr = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!newstr)
		return (NULL);
		while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	return (newstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	newstr = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		newstr[i++] = s2[j++];
	free(s1);
	return (newstr);
}