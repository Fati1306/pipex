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

static void	init(int ac, char **av, t_args *s, char **env)
{
	if (ac != 5)
		perror_exit("incorrect number of arguments", 1);
	parse_args(ac, av, s);
	parse_path(env, s);
	get_exec_args(s, ac);
}

static void	exec_pipe(t_args s, char **env)
{
	int		pid;
	int		fd[2];

	if (pipe(fd) == -1)
		perror_exit(NULL, 1);
	pid = fork();
	if (pid == -1)
		perror_exit(NULL, 1);
	else if (pid == 0)
	{
		if (close(fd[0]) == -1 || dup2(fd[1], 1) == -1 || close(fd[1]) == -1)
			perror_exit(NULL, 1);
		execve(s.exec_args[0][0], s.exec_args[0] + 1, env);
		perror_exit(NULL, 1);
	}
	else
	{
		if (close(fd[1]) == -1 || dup2(fd[0], 0) == -1 || close(fd[0]) == -1)
			perror_exit(NULL, 1);
		if (waitpid(pid, NULL, 0) == -1)
			perror_exit(NULL, 1);
	}
}

int	main(int ac, char **av, char **env)
{
	t_args	s;

	init(ac, av, &s, env);
	dup2(s.file1, 0);
	if (close(s.file1) == -1)
		perror_exit(NULL, 1);
	exec_pipe(s, env);
	dup2(s.file2, 1);
	if (close(s.file2) == -1)
		perror_exit(NULL, 1);
	execve(s.exec_args[1][0], s.exec_args[1] + 1, env);
	return (0);
}
