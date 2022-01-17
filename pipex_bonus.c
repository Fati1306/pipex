#include "pipex.h"

static void	init(int ac, char **av, t_args *s, char **env)
{
	if (ac < 5
		|| (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0 && ac != 6))
		perror_exit("incorrect number of arguments", 1);
	parse_args(ac, av, s);
	parse_path(env, s);
	get_exec_args(s, ac);
}

static void	exec_pipe(t_args *s, int p, char **env, char **av)
{
	if (p == 0)
	{
		if (dup2(s->fd[0][0], 0) == -1 || dup2(s->fd[1][1], 1) == -1
			|| close(s->fd[1][0]) == -1 || close(s->fd[1][1]))
			perror_exit(NULL, 1);
		execve(s->exec_args[0][0], s->exec_args[0] + 1, env);
		perror_exit(NULL, 1);
	}
	else if (p == 1)
	{
		if (dup2(s->fd[1][0], 0) == -1 || dup2(s->fd[0][1], 1) == -1
			|| close(s->fd[1][0]) == 1 || close(s->fd[1][1]) == -1)
			perror_exit(NULL, 1);
		if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
			unlink("temp");
		execve(s->exec_args[1][0], s->exec_args[1] + 1, env);
		perror_exit(NULL, 1);
	}
}

int	main(int ac, char **av, char **env)
{
	t_args	s;
	int		pid;

	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
		s.count = 3;
	else
		s.count = 2;
	init(ac, av, &s, env);
	pid = fork();
	if (pid == -1)
		perror_exit(NULL, 1);
	if (pid == 0)
		exec_pipe(&s, 0, env, av);
	else
		exec_pipe(&s, 1, env, av);
	close(s.fd[0][0]);
	close(s.fd[0][1]);
	if (waitpid(pid, NULL, 0) == -1)
		perror_exit(NULL, 1);
	return (0);
}
