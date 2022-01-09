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
#include <stdio.h>

void	parse_args(int ac, char	**av, t_args *s)
{
	int	i;

	i = 2;
	s->f1 = open(av[1], O_RDONLY);
	s->f2 = open(av[ac - 1], O_WRONLY | O_TRUNC);
	s->cmds = (char ***) malloc(sizeof(char **) * (ac - 2));
	if (s->f1 == -1 || s->f2 == -1 || s->cmds == NULL)
	perror_exit(NULL);
	while (i < ac - 1)
	{
		s->cmds[i - 2] = ft_split(av[i], ' ');
		i++;
	}
	s->cmds[i - 2] = NULL;
}
