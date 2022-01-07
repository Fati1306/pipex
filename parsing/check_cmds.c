/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:42:43 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/07 11:47:40 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdio.h>

static int	check_cmd_access(char *cmd_path)
{
	if (access(cmd_path, F_OK) == -1 || access(cmd_path, X_OK) == -1)
		return (-1);
	return (1);
}

static void	alloc_cmd_args(t_args *s, char *cmd_path, int j)
{
	s->exec_args[j] = (char **) malloc(sizeof(char *));
	s->exec_args[j][0] = ft_strdup(cmd_path);
	if (ft_strchr(s->cmds[j], ' ') == 1)
	{
		ft_split(s->cmds[j], ' ');
	}
	else
	{
		s->exec_args[j][1] = ft_strdup(s->cmds[j]);
		s->exec_args[j][2] = NULL;
	}
}

void	check_cmds(t_args *s, int ac)
{
	char	*cmd_path;
	int		i;
	int		j;

	j = 0;
	s->exec_args = (char ***) malloc(sizeof(char **) * (ac - 2));
	while (s->cmds[j])
	{
		i = 0;
		while (s->paths[i])
		{
			cmd_path = ft_strjoin(s->paths[i], s->cmds[j], 0);
			printf("\n%s", cmd_path);
			if (check_cmd_access(cmd_path) == 1)
			{
				alloc_cmd_args(s, cmd_path, j);
				printf("\n\tcmd found");
				printf("\n\tpath is: %s", s->exec_args[j][0]);
				free(cmd_path);
				break ;
			}
			free(cmd_path);
			i++;
		}
		j++;
	}
}
