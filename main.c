/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste < ccoste@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:06:29 by ccoste            #+#    #+#             */
/*   Updated: 2022/12/09 16:14:39 by ccoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int	fd;
	char *line;

	fd = open("test", O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break;
		}
		printf("%s", line);
		free(line);
	}
	return(0);
}
