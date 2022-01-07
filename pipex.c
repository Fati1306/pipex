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
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	t_args	s;

	parse_args(ac, av, &s);
	parse_path(env, &s);
	check_cmds(&s, ac);
	// system("leaks pipex");
	return (0);
}
