/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:08:31 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/18 12:08:40 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	read_here_doc(t_args *s, char *limiter, char **av, int ac)
{
	char	*line;

	s->file1 = open("temp", O_RDWR | O_CREAT | O_APPEND, 0644);
	s->file2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND);
	if (s->file1 == -1 || s->file2 == -1)
		perror_exit(NULL, 1);
	if (write(1, "heredoc> ", 10) == -1)
		perror_exit(NULL, 1);
	line = get_next_line(0);
	while (line && ft_strncmp(line, limiter, ft_strlen(line) - 1) != 0)
	{
		if (write(s->file1, line, ft_strlen(line)) == -1
			|| write(1, "heredoc> ", 10) == -1)
			perror_exit(NULL, 1);
		free(line);
		line = get_next_line(0);
	}
	close(s->file1);
	s->file1 = open("temp", O_RDONLY, 0444);
	if (s->file1 == -1)
		perror_exit(NULL, 1);
}

static void	init_fd(t_args *s, int ac, char **av)
{
	if (s->count == 3)
		read_here_doc(s, av[2], av, ac);
	else
	{
		s->file1 = open(av[1], O_RDONLY);
		s->file2 = open(av[ac - 1], O_WRONLY | O_TRUNC);
		if (s->file1 == -1 || s->file2 == -1)
			perror_exit(NULL, 1);
	}
}

void	parse_args(int ac, char	**av, t_args *s)
{
	int	i;

	i = s->count;
	init_fd(s, ac, av);
	s->cmds = (char ***) malloc(sizeof(char **) * (ac - s->count));
	if (s->cmds == NULL)
		perror_exit(NULL, 1);
	while (i < ac - 1)
	{
		s->cmds[i - s->count] = ft_split(av[i], ' ');
		if (s->cmds[i - s->count] == NULL)
			perror_exit(NULL, 1);
		i++;
	}
	s->cmds[i - s->count] = NULL;
}
