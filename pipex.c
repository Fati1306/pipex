/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 07:30:25 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/07 11:48:01 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	perror_exit(char *err_msg)
{
	perror(err_msg);
	exit(0);
}

static void	init(int ac, char **av, t_args *s, char **env)
{
	if (ac != 5)
		perror_exit("incorrect number of arguments\n");
	parse_args(ac, av, s);
	parse_path(env, s);
	check_cmds(s, ac);
}

static void	exec_pipe(t_args *s, int p, char **env)
{
	if (p == 0)
	{
		if (dup2(s->f1, 0) == -1 || dup2(s->fd[1], 1) == -1
			|| close(s->fd[0]) == -1 || close(s->fd[1]))
			perror_exit(NULL);
		execve(s->exec_args[0][0], s->exec_args[0] + 1, env);
		perror_exit(NULL);
	}
	else if (p == 1)
	{
		if (dup2(s->fd[0], 0) == -1 || dup2(s->f2, 1) == -1
			|| close(s->fd[0]) == 1 || close(s->fd[1]) == -1)
			perror_exit(NULL);
		execve(s->exec_args[1][0], s->exec_args[1] + 1, env);
		perror_exit(NULL);
	}
}

int	main(int ac, char **av, char **env)
{
	t_args	s;
	int		pid1;
	int		pid2;

	init(ac, av, &s, env);
	pid1 = fork();
	pid2 = fork();
	if (pid1 == -1 || pid2 == -1)
		perror_exit(NULL);
	if (pid1 == 0)
		exec_pipe(&s, 0, env);
	else if (pid2 == 0)
		exec_pipe(&s, 1, env);
	close(s.f1);
	close(s.f2);
	close(s.fd[0]);
	close(s.fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
