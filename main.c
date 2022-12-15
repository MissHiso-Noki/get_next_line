/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste <ccoste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:06:29 by ccoste            #+#    #+#             */
/*   Updated: 2022/12/12 15:03:43 by ccoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open("../test", O_RDONLY);
	while (i < 21)
	{
		line = get_next_line(fd);
		if (!line)
			printf("ligne %i : %s\n", i, line);
		else
			printf("ligne %i : %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
