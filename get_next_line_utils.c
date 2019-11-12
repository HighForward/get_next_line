/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:36:20 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/12 18:00:42 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen_gnl(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr_gnl(char *s, char c)
{
	int		i;
	char	*str;

	str = (char*)s;
	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (i);
}

char *ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*join;
	char	*s;
	char	*d;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s = (char*)s1;
	d = (char*)s2;
	if (!(join = (char*)malloc(sizeof(char) * ((ft_strlen_gnl(s)) + (ft_strlen_gnl(d)) + 1))))
		return (NULL);
	while (s[i])
	{
		join[j] = s[i];
		i++;
		j++;
	}
	i = 0;
	while(d[i])
	{
		join[j] = d[i];
		i++;
		j++;
	}
	join[j] = '\0';
	return (join);
}

char *ft_cutfinal_gnl(char *s, int size)
{
	int i;
	char *ligne;
	i = 0;

	ligne = (char*)malloc(sizeof(char) * size + 1);
	while(i < size && s[i])
	{
		ligne[i] = s[i];
		i++;
	}
	ligne[i] = '\0';
	free(s);
	return (ligne);
}

char *ft_cutnext_gnl(char *s, int size)
{
	int i;
	char *next;

	i = 0;
	if (size < ft_strlen_gnl(s))
	{
		while(s[size] == '\n' && s[size])
			size++;
	
		next = (char*)malloc(sizeof(char) * ft_strlen_gnl(s) - size + 1);
		while (size < ft_strlen_gnl(s) && s[size])
		{
			next[i] = s[size];
			size++;
			i++;
		}
		next[i] = '\0';
	}
	else
		next = NULL;
	return (next);
}
