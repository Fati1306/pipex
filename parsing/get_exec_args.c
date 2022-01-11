#include "../pipex.h"

static int	check_cmd_access(char *cmd_path, int *access_err)
{
	if (access(cmd_path, F_OK) == -1)
	{
		*access_err = 127;
		if (access(cmd_path, X_OK) == -1)
			*access_err = 126;
		return (0);
	}
	return (1);
}

static void	alloc_cmd_args(t_args *s, char **cmd_path, int j)
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
	if (s->exec_args[j] == NULL)
		free_cmd_path(cmd_path);
	s->exec_args[j][l++] = ft_strdup(*cmd_path);
	if (s->exec_args[j][l - 1] == NULL)
		free_cmd_path(cmd_path);
	while (s->cmds[j][i])
	{
		s->exec_args[j][l] = ft_strdup(s->cmds[j][i]);
		if (s->exec_args[j][l] == NULL)
			free_cmd_path(cmd_path);
		l++;
		i++;
	}
	s->exec_args[j][l] = NULL;
}

static void	check_cmd(t_args *s, int j, int *checker, int *access_err)
{
	char	*cmd_path;

	cmd_path = ft_strdup(s->cmds[j][0]);
	if (cmd_path == NULL)
		perror_exit(NULL, 1);
	if (check_cmd_access(cmd_path, access_err) == 1)
	{
		alloc_cmd_args(s, &cmd_path, j);
		*checker = 1;
	}
	free(cmd_path);
}

static void	check_cmd_paths(t_args *s, int j, int *checker, int *access_err)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (s->paths[i])
	{
		cmd_path = ft_strjoin(s->paths[i], s->cmds[j][0], 0);
		if (cmd_path == NULL)
			perror_exit(NULL, 1);
		if (check_cmd_access(cmd_path, access_err) == 1)
		{
			alloc_cmd_args(s, &cmd_path, j);
			free(cmd_path);
			*checker = 1;
			return ;
		}
		free(cmd_path);
		i++;
	}
}

void	get_exec_args(t_args *s, int ac)
{
	int		j;
	int		checker;
	int		access_err;

	s->exec_args = (char ***) malloc(sizeof(char **) * (ac - 2));
	if (s->exec_args == NULL)
		perror_exit(NULL, 1);
	j = 0;
	while (s->cmds[j])
	{
		checker = 0;
		if (s->cmds[j][0][0] == '.' || s->cmds[j][0][0] == '/')
			check_cmd(s, j, &checker, &access_err);
		else
			check_cmd_paths(s, j, &checker, &access_err);
		if (!checker)
			perror_exit(NULL, access_err);
		j++;
	}
}

// void	alloc_exec_args(t_args *s, int ac)
// {
// 	char	*cmd_path;
// 	int		i;
// 	int		j;
// 	int		checker;

// 	j = 0;
// 	s->exec_args = (char ***) malloc(sizeof(char **) * (ac - 2));
// 	while (s->cmds[j])
// 	{
// 		i = 0;
// 		checker = 0;
// 		while (s->paths[i])
// 		{
// 			if (s->cmds[j][0][0] == '.' || s->cmds[j][0][0] == '/')
// 				cmd_path = ft_strdup(s->cmds[j][0]);
// 			else
// 				cmd_path = ft_strjoin(s->paths[i], s->cmds[j][0], 0);
// 			if (check_cmd_access(cmd_path) == 1)
// 			{
// 				alloc_cmd_args(s, cmd_path, j);
// 				free(cmd_path);
// 				checker = 1;
// 				break ;
// 			}
// 			free(cmd_path);
// 			i++;
// 		}
// 		if (!checker)
// 			perror_exit(NULL, 127);
// 		j++;
// 	}
// }
