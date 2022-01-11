/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:07:16 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/07 10:21:20 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	add_slash(t_args *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s->paths[j])
	{
		s->paths[j] = ft_strjoin(s->paths[j], "/", 1);
		j++;
	}
}

void	parse_path(char **env, t_args *s)
{
	int	j;

	j = 0;
	while (env[j])
	{
		if (env[j][0] == 'P' && env[j][1] == 'A' && env[j][2] == 'T'
		&& env[j][3] == 'H' && env[j][4] == '=')
		{
			s->paths = ft_split(env[j] + 5, ':');
			if (s->paths == NULL)
				perror_exit(NULL, 1);
		}
		j++;
	}
	add_slash(s);
}
