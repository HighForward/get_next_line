/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:36:20 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/13 15:14:17 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (i);
}

char *find_rest(char *s, int cut)
{
	return (&s[cut]);
}

char *ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(join = (char*)malloc(sizeof(char) * ((ft_strlen(s1)) + (ft_strlen(s2)) + 1))))
		return (NULL);
	while (s1[i])
	{
		join[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while(s2[i])
	{
		join[j] = s2[i];
		i++;
		j++;
	}
	join[j] = '\0';
	return (join);
}

