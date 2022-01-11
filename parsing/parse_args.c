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

void	parse_args(int ac, char	**av, t_args *s)
{
	int	i;

	i = 2;
	s->f1 = open(av[1], O_RDONLY);
	s->f2 = open(av[ac - 1], O_WRONLY | O_TRUNC);
	if (s->f1 == -1 || s->f2 == -1)
		perror_exit(NULL, 1);
	if (pipe(s->fd) == -1)
		perror_exit(NULL, 1);
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
