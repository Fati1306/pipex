
#include "../pipex.h"
#include <stdio.h>

static int	count_spaces(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

static int	check_cmd_access(char *cmd_path)
{
	if (access(cmd_path, F_OK) == -1 || access(cmd_path, X_OK) == -1)
		return (-1);
	return (1);
}

static void	alloc_cmd_args(t_args *s, char *cmd_path, int j)
{
	int	len;

	len = count_spaces(s->cmds[j]);
	s->exec_args[j] = (char **) malloc(sizeof(char *) * (2 + len));
	s->exec_args[j][0] = ft_strdup(cmd_path);
	// if (len > 1)
	// {
	// 	// ft_split();
	// }
	// else
	// {
		s->exec_args[j][1] = ft_strdup(s->cmds[j]);
		s->exec_args[j][2] = NULL;
	// }
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
			cmd_path = ft_strjoin(s->paths[i], s->cmds[j], 2);
			printf("\n%s", cmd_path);
			if (check_cmd_access(cmd_path) == 1)
			{
				alloc_cmd_args(s, cmd_path, j);
				printf("\n\tcmd found");
				printf("\n\tcmd path: %s", cmd_path);
				printf("\n\tpath is: %s", s->exec_args[j][0]);
				printf(" cmd is: %s", s->exec_args[j][1]);
				free(cmd_path);
				break ;
			}
			free(cmd_path);	
			i++;
		}
		printf("\n");
		j++;
	}
}
