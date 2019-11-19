/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:59:23 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/18 12:47:11 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(int size)
{
	char *new;

	if (!(new = malloc(sizeof(char) * size + 1)))
		return (NULL);
	new[size] = '\0';
	while (size--)
		new[size] = '\0';
	return (new);
}

int		ft_strlen(char *s)
{
	int	i;
	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int size;

	size = ft_strlen(dest);
	i = 0;
	while (i < nb && src[i])
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return(dest);
}

int		ft_is_line(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
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

