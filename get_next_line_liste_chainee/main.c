/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste <ccoste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:06:29 by ccoste            #+#    #+#             */
/*   Updated: 2023/02/02 11:19:34 by ccoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	int		i;
	char	*line1;

	i = 0;
	fd1 = open("test_get_next_line1", O_RDONLY);
	line1 = get_next_line(fd1);
	while (line1)
	{
		printf("ligne %i du fichier 1 : %s\n", i, line1);
		free(line1);
		line1 = get_next_line(fd1);
		i++;
	}
	close(fd1);
	return (0);
}
