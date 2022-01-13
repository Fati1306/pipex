/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:07:11 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/07 10:34:12 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	init_fd(t_args *s, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac - 2)
	{
		s->fd[i] = (int *) malloc(sizeof(int) * 2);
		if (s->fd[i] == NULL)
			perror_exit(NULL, 1);
		if (i == 0)
		{
			s->fd[i][0] = open(av[1], O_RDONLY);
			s->fd[i][1] = open(av[ac - 1], O_WRONLY | O_TRUNC);
			if (s->fd[i][0] == -1 || s->fd[i][1] == -1)
				perror_exit(NULL, 1);
		}
		else
		{
			if (pipe(s->fd[i]) == -1)
				perror_exit(NULL, 1);
		}
		i++;
	}
}

void	parse_args(int ac, char	**av, t_args *s)
{
	int	i;

	i = 2;
	init_fd(s, ac, av);
	s->cmds = (char ***) malloc(sizeof(char **) * (ac - 2));
	if (s->cmds == NULL)
		perror_exit(NULL, 1);
	while (i < ac - 1)
	{
		s->cmds[i - 2] = ft_split(av[i], ' ');
		if (s->cmds[i - 2] == NULL)
			perror_exit(NULL, 1);
		i++;
	}
	s->cmds[i - 2] = NULL;
}
