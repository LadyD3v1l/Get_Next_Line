/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga <jobraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:02:20 by jobraga           #+#    #+#             */
/*   Updated: 2025/05/05 19:02:20 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*bloc_convert_line(char *bloc)
{
	int		i;
	char	*line;

	i = 0;
	if (!bloc || bloc[0] == '\0')
		return (NULL);
	while (bloc[i] != '\n' && bloc[i] != '\0')
		i++;
	line = ft_substr_line(bloc, 0, i + 1);
	return (line);
}

static char	*bloc_new_bloc(char *bloc)
{
	int		i;
	char	*new;

	i = 0;
	while (bloc[i] != '\n' && bloc[i] != '\0')
		i++;
	if (bloc[i] == '\0')
	{
		free(bloc);
		return (NULL);
	}
	new = ft_substr_line(bloc, i + 1, ft_strlen(bloc + i + 1));
	free(bloc);
	return (new);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char *bloc;

	if (0 == fd || BUFFER_SIZE <= 0)
	return (NULL);
	if (!bloc)
	{
		bloc = malloc(1);
		bloc[0] = '\0';
	}
	bloc = read_and_copied(fd, bloc);
	if (!bloc)
		return (NULL);
	line = bloc_convert_line(bloc);
	bloc = bloc_new_bloc(bloc);
	return (line);
}
