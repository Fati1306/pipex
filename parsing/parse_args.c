/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:07:11 by fel-maac          #+#    #+#             */
/*   Updated: 2022/02/01 10:56:26 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	init_fd(t_args *s, int ac, char **av)
{
	s->file1 = open(av[1], O_RDONLY);
	s->file2 = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (s->file1 == -1 || s->file2 == -1)
		perror_exit(NULL, 1);
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
