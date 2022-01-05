/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:07:11 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/05 12:14:38 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdio.h>

void	parse_args(int ac, char	**av, t_args *s)
{
	int	i;

	i = 2;
	s->file1 = ft_strdup(av[1]);
	s->file2 = ft_strdup(av[ac - 1]);
	printf("%s %s", s->file1, s->file2);
	s->cmds = (char **) malloc(sizeof(char *) * (ac - 3));
	while (i < ac - 1)
	{
		s->cmds[i - 2] = ft_strdup(av[i]);
		i++;
	}
	i = 0;
	printf("\n");
	while (i < ac - 3)
	{
		printf("%s ", s->cmds[i]);
		i++;
	}
}