/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:42:43 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/05 13:00:32 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdio.h>

//static	check_if_cmd_exists()
//{}

void	check_cmds(t_args *s)
{
	char	*cmd_path;

	cmd_path = ft_strjoin(s->paths[0], s->cmds[0]);
	printf("\n\n%s", cmd_path);
	(void)s;
}
