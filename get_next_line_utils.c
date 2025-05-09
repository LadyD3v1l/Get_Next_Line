/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga- <jobraga-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:02:32 by jobraga           #+#    #+#             */
/*   Updated: 2025/05/09 17:59:14 by jobraga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcheck(const char *str, char c)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr_line(char *bloc, unsigned int start, size_t end)
{
	size_t	i;
	char	*sub;

	if (!bloc)
		return (NULL);
	if (end == 0 || start > ft_strlen(bloc))
	{
		sub = malloc(1);
		sub[0] = '\0';
		return (sub);
	}
	sub = malloc(end + 1);
	i = 0;
	while (bloc[i + start] && i < end && start < ft_strlen(bloc))
	{
		sub[i] = bloc[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(const char *line, const char *rest)
{
	size_t	l;
	char	*bloc;

	if (!line && !rest)
		return (NULL);
	if (!line)
		return (ft_substr_line((char *)rest, 0, ft_strlen(rest)));
	if (!rest)
		return (ft_substr_line((char *)line, 0, ft_strlen(line)));
	bloc = malloc(ft_strlen(line) + ft_strlen(rest) + 1);
	if (!bloc)
		return (NULL);
	l = 0;
	while (*line)
	{
		bloc[l] = *line++;
		l++;
	}
	while (*rest)
	{
		bloc[l] = *rest++;
		l++;
	}
	bloc[l] = '\0';
	return (bloc);
}

char	*read_and_copied(int fd, char *bloc)
{
	ssize_t		bytes;
	char		*buffer;
	char		*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strcheck(bloc, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(bloc);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		temp = bloc;
		bloc = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (bloc);
}
