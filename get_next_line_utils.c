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

int ft_strlen_gnl(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*d;
	unsigned int	i;

	d = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		d[i] = 0;
		i++;
	}
	s = (void*)d;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if (!(temp = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(temp, nmemb * size);
	return (temp);
}

int	ft_strchr_gnl(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (i + 1);
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

