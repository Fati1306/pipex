/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 07:58:05 by fel-maac          #+#    #+#             */
/*   Updated: 2021/11/23 14:24:10 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*ft_check_line(char *buffer, char **line)
{
	char	*after_line;

	after_line = ft_strchr(buffer, '\n');
	if (after_line)
	{
		*after_line = '\0';
		after_line++;
		*line = ft_strjoin(*line, buffer, 1);
		*line = ft_strjoin(*line, "\n", 1);
		ft_strcpy(buffer, after_line);
	}
	else
		*line = ft_strjoin(*line, buffer, 1);
	return (after_line);
}

char	*get_next_line(int fd)
{
	char		*after_line;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	static int	check = 1;

	if (read(fd, buffer, 0) == -1 || BUFFER_SIZE <= 0 || check == -1)
		return (NULL);
	line = ft_strdup("");
	if (line == NULL)
		return (NULL);
	after_line = ft_check_line(buffer, &line);
	while (!after_line && check > 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
		{
			free(line);
			return (NULL);
		}
		buffer[check] = '\0';
		after_line = ft_check_line(buffer, &line);
	}
	if (!after_line && check == 0)
		check = -1;
	return (line);
}
