/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:46:44 by fel-maac          #+#    #+#             */
/*   Updated: 2022/01/06 12:01:36 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2, int check)
{
	char	*str;
	int		i;
	int		j;
	size_t	len;

	str = NULL;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc (sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
		str[j++] = s1[i++];
	if (check == 1)
		free((char *)s1);
	i = 0;
	while (s2[i])
	{
		if (check == 2 && s2[i] == ' ')
		{
			j++;
			break ;
		}
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}
