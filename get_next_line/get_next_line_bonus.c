/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste <ccoste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:36:30 by ccoste            #+#    #+#             */
/*   Updated: 2023/01/05 10:46:37 by ccoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	int			rd_bytes;

	rd_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	stash[fd] = read_and_stash(fd, stash[fd], rd_bytes);
	if (!stash[fd])
	{
		return (NULL);
	}
	line = extract_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}

// utilise read pour add characters dans la stash
char	*read_and_stash(int fd, char *stash, int rd_bytes)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		return (NULL);
	}
	while (!found_newline(stash) && rd_bytes != 0)
	{
		rd_bytes = (int)read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

// extrait tout les caractere de la stash et les stock dans la line
// stop apres le premier \n rencontrer
char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	line = calloc_extract_line(line, stash);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			line[i] = '\n';
			i++;
			break ;
		}
		else
		{
			line[i] = stash[i];
			i++;
		}
	}
	return (line);
}

// apres avoir extrait stash dans line, plus besoin des caractere dans stash
// cette fonction clear la stash seulement les caractere non retourner
// a la fin de get_next_line() sont toujours dans la static stash
char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*clean;

	i = 0;
	j = 0;
	clean = NULL;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	clean = ft_calloc(sizeof(char), (ft_strlen(stash) - i + 1));
	if (!clean)
		return (NULL);
	i++;
	while (stash[i])
	{
		clean[j++] = stash[i++];
	}
	free(stash);
	return (clean);
}

char	*calloc_extract_line(char *line, char *stash)
{
	int	len;

	len = generate_line(stash);
	line = ft_calloc(sizeof(char), (len + 1));
	if (len == 0 || !line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
