/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 07:30:25 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/05 12:16:18 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	t_args	*s;

	s = (t_args *) malloc(sizeof(t_args));
	parse_args(ac, av, s);
	parse_path(env);
	return (0);
}
