/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:48:46 by mbrignol          #+#    #+#             */
/*   Updated: 2019/11/18 18:26:57 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stdio.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	char	*line;
	int i;
	(void)ac;
	int check;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while ((check = get_next_line(fd, &line)) == 1)
	{
		printf("%s | %d\n", line, check);
		i++;
	}
	printf("%s | %d\n", line, check);
}