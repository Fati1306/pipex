/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:07:05 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/18 12:11:14 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init(int ac, char **av, t_args *s, char **env)
{
	if (ac < 5 || (s->count == 3 && ac < 6))
		perror_exit("incorrect number of arguments", 1);
	parse_args(ac, av, s);
	parse_path(env, s);
	get_exec_args(s, ac);
}

static void	exec_pipe(t_args s, int i, char **env)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		perror_exit(NULL, 1);
	pid = fork();
	if (pid == -1)
		perror_exit(NULL, 1);
	else if (pid == 0)
	{
		if (close(fd[0]) == -1 || dup2(fd[1], 1) == -1 || close(fd[1]) == -1)
			perror_exit(NULL, 1);
		execve(s.exec_args[i][0], s.exec_args[i] + 1, env);
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
	int		i;

	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
		s.count = 3;
	else
		s.count = 2;
	init(ac, av, &s, env);
	i = -1;
	dup2(s.file1, 0);
	if (close(s.file1) == -1)
		perror_exit(NULL, 1);
	while (++i < ac - s.count - 2)
		exec_pipe(s, i, env);
	dup2(s.file2, 1);
	if (close(s.file2) == -1)
		perror_exit(NULL, 1);
	if (s.count == 3)
		unlink("temp");
	execve(s.exec_args[i][0], s.exec_args[i] + 1, env);
	return (0);
}
