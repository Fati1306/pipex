/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 07:30:18 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/05 12:14:50 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>

typedef struct	s_args
{
	char	**paths;
	char	*file1;
	char	*file2;
	char	**cmds;
} t_args;

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

void	parse_args(int ac, char	**av, t_args *ss);
void	parse_path(char **env);

#endif