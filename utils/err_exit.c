/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:09:11 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/18 12:09:11 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
