/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:07:16 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/05 12:59:19 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdio.h>

static void	add_slash(t_args *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s->paths[j])
	{
		s->paths[j] = ft_strjoin(s->paths[j], "/");
		j++;
	}
}

void	parse_path(char **env, t_args *s)
{
	int	j;

	j = 0;
	printf("\n\n");
	while (env[j])
	{
		if (env[j][0] == 'P' && env[j][1] == 'A' && env[j][2] == 'T'
		&& env[j][3] == 'H' && env[j][4] == '=')
		{
			s->paths = ft_split(env[j] + 5, ':');
		}
		j++;
	}
	add_slash(s);
	j = 0;
	while (s->paths[j])
	{
		printf("%s\n", s->paths[j]);
		j++;
	}
}
