/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste <ccoste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:06:29 by ccoste            #+#    #+#             */
/*   Updated: 2022/12/21 11:34:14 by ccoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	//int		fd2;
	int		i;
	char	*line1;
	//char	*line2;

	i = 0;
	fd1 = open("test_get_next_line1", O_RDONLY);
	//fd2 = open("test_get_next_line2", O_RDONLY);
	//fd = 1;
	line1 = get_next_line(fd1);
	//line2 = get_next_line(fd2);
	while (line1 /*|| line2*/)
	{
		printf("ligne %i du fichier 1 : %s\n", i, line1);
		free(line1);
		line1 = get_next_line(fd1);
		// printf("ligne %i du fichier 2 : %s\n", i, line2);
		// free(line2);
		// line2 = get_next_line(fd2);
		i++;
	}
	close(fd1);
	//close(fd2);
	return (0);
}
