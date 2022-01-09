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
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	t_args	s;
	int		pid1;
	int		pid2;
	int		fd[2];

	parse_args(ac, av, &s);
	parse_path(env, &s);
	check_cmds(&s, ac);
	pipe(fd);
	pid1 = fork();
	pid2 = fork();
	if (pid1 == -1 || pid2 == -1)
		perror_exit(NULL);
	if (pid1 == 0)
	{
		dup2(s.f1, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execve(s.exec_args[0][0], s.exec_args[0] + 1, env);
	}
	else if (pid2 == 0)
	{
		dup2(fd[0], 0);
		dup2(s.f2, 1);
		close(fd[0]);
		close(fd[1]);
		execve(s.exec_args[1][0], s.exec_args[1] + 1, env);
	}
	// else
	// 	system("leaks pipex");
	close(s.f1);
	close(s.f2);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
