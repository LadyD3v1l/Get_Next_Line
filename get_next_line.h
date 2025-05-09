/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobraga <jobraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:02:54 by jobraga           #+#    #+#             */
/*   Updated: 2025/05/05 19:02:54 by jobraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(const char *str);
int		ft_strcheck(const char *str, char c);
char	*ft_strjoin(const char *line, const char *rest);
char	*read_and_copied(int fd, char *bloc);
char	*ft_substr_line(char *bloc, unsigned int start, size_t end);
char	*get_next_line(int fd);

#endif
