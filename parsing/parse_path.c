/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:07:16 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/05 12:17:18 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdio.h>

void	parse_path(char **env)
{
	int		j;
	char	**paths;

	j = 0;
	while (env[j])
	{
		if (env[j][0] == 'P' && env[j][1] == 'A' && env[j][2] == 'T' && env[j][3] == 'H' && env[j][4] == '=')
		{
			paths = ft_split(env[j] + 5, ':');
			j = 0;
			while (paths[j])
			{
				printf("%s\n", paths[j]);
				j++;
			}
		}
		j++;
	}
}
