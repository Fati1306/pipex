/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 07:30:18 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/31 12:03:04 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define BUFFER_SIZE 1

typedef struct s_args
{
	int		file1;
	int		file2;
	char	***cmds;
	char	**paths;
	char	***exec_args;
	int		count;
}	t_args;

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2, int check);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dst, char *src);
char	*get_next_line(int fd);

void	parse_args(int ac, char	**av, t_args *s);
void	parse_path(char **env, t_args *s);
void	get_exec_args(t_args *s, int ac);

void	perror_exit(char *err_msg, int err);
void	free_cmd_path(char **cmd_path);

#endif