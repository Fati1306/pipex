/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 07:30:18 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/07 10:57:03 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_args
{
	int		f1;
	int		f2;
	int		fd[2];
	char	***cmds;
	char	**paths;
	char	***exec_args;
}	t_args;

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2, int check);
int		ft_strchr(char *str, int c);

void	parse_args(int ac, char	**av, t_args *s);
void	parse_path(char **env, t_args *s);
void	check_cmds(t_args *s, int ac);

void	perror_exit(char *err_msg);

#endif