#include "../pipex.h"

void	perror_exit(char *err_msg, int err)
{
	perror(err_msg);
	exit(err);
}

void	free_cmd_path(char **cmd_path)
{
	free(*cmd_path);
	perror_exit(NULL, 1);
}
