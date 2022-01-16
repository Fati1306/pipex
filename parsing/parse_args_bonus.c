
#include "../pipex.h"

static void	read_here_doc(t_args *s, char *limiter)
{
	char	*line;

	s->fd[0][0] = open("temp", O_RDWR | O_CREAT | O_APPEND, 0644);
	if (s->fd[0][0] == -1)
		perror_exit(NULL, 1);
	write(1, "heredoc> ", 10);
	line = get_next_line(0);
	while (line && ft_strncmp(line, limiter, ft_strlen(line) - 1) != 0)
	{
		write(s->fd[0][0], line, ft_strlen(line));
		write(1, "heredoc> ", 10);
		free(line);
		line = get_next_line(0);
	}
	close(s->fd[0][0]);
	s->fd[0][0] = open("temp", O_RDONLY, 0444);
}

static void	init_fd(t_args *s, int ac, char **av, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac - count)
	{
		s->fd[i] = (int *) malloc(sizeof(int) * 2);
		if (s->fd[i] == NULL)
			perror_exit(NULL, 1);
		if (i == 0)
		{
			if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
			{
				read_here_doc(s, av[2]);
				s->fd[i][1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND);
			}
			else
			{
				s->fd[i][0] = open(av[1], O_RDONLY);
				s->fd[i][1] = open(av[ac - 1], O_WRONLY | O_TRUNC);
			}
			if (s->fd[i][0] == -1 || s->fd[i][1] == -1)
				perror_exit(NULL, 1);
		}
		else
			if (pipe(s->fd[i]) == -1)
				perror_exit(NULL, 1);
		i++;
	}
}

void	parse_args(int ac, char	**av, t_args *s)
{
	int	i;
	int	count;

	i = 2;
	count = 2;
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
	{
		count = 3;
		i = 3;
	}
	init_fd(s, ac, av, count);
	s->cmds = (char ***) malloc(sizeof(char **) * (ac - count));
	if (s->cmds == NULL)
		perror_exit(NULL, 1);
	while (i < ac - 1)
	{
		s->cmds[i - count] = ft_split(av[i], ' ');
		if (s->cmds[i - count] == NULL)
			perror_exit(NULL, 1);
		i++;
	}
	s->cmds[i - count] = NULL;
}
