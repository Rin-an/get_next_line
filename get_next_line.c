/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <ssadiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:44:16 by ssadiki           #+#    #+#             */
/*   Updated: 2022/03/24 19:52:01 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *s)
{
	int		i;
	char	*r;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	r = (char *)malloc(i + 2);
	if (!r)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		r[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_keep(char *s)
{
	int		i;
	char	*r;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	r = (char *)malloc(ft_strlen(s) - i + 1);
	if (!r)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		r[j++] = s[i++];
	r[j] = '\0';
	free(s);
	return (r);
}

char	*ft_read(char *s, int fd)
{
	int		i;
	char	*b;

	b = (char *) malloc(BUFFER_SIZE + 1);
	if (!b)
		return (NULL);
	i = 1;
	while (!is_nl(s) && i)
	{
		i = read(fd, b, BUFFER_SIZE);
		if (i < 0)
		{
			free(b);
			return (NULL);
		}
		b[i] = '\0';
		s = ft_strjoin(s, b);
	}
	free (b);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*l;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s = ft_read(s, fd);
	if (!s)
		return (NULL);
	l = ft_line(s);
	s = ft_keep(s);
	return (l);
}
