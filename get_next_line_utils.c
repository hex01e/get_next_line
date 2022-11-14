/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houmanso <houmanso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:44:35 by houmanso          #+#    #+#             */
/*   Updated: 2022/11/14 14:58:09 by houmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	unsigned long i;

	i = 0;
	p = malloc(count * size);
	if (p)
		while (i < count * size)
			p[i++] = 0;
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		newlen;
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	newlen = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *) malloc((newlen + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	free((char *)s1);
	return (newstr);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*p;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	p = (char *) malloc(len * sizeof(char) + 1);
	if (!p)
		return (p);
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		sublen;
	char		*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return ("");
	sublen = ft_strlen(&s[start]);
	if (len > sublen)
		len = sublen;
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	free((char *)s);
	return (sub);
}
