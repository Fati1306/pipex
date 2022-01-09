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
	int	i;
	int	l;
	int	len;

	i = 0;
	l = 0;
	len = 0;
	while (s->cmds[j][len])
		len++;
	s->exec_args[j] = (char **) malloc(sizeof(char *) * (2 + len));
	s->exec_args[j][l++] = ft_strdup(cmd_path);
	while (s->cmds[j][i])
	{
		s->exec_args[j][l] = ft_strdup(s->cmds[j][i]);
		l++;
		i++;
	}
	s->exec_args[j][l] = NULL;
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
			cmd_path = ft_strjoin(s->paths[i], s->cmds[j][0], 0);
			if (check_cmd_access(cmd_path) == 1)
			{
				alloc_cmd_args(s, cmd_path, j);
				free(cmd_path);
				break ;
			}
			free(cmd_path);
			i++;
		}
		j++;
	}
}
