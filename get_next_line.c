/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste < ccoste@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:51:03 by ccoste            #+#    #+#             */
/*   Updated: 2022/12/09 16:30:37 by ccoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			read;

	read = 1;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	read_and_stash(fd, &stash, &read);
	if (stash == NULL)
	{
		return (NULL);
	}
	extract_line(stash, line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

// utilise read pour add characters dans la stash
void	read_and_stash(int fd, char **stash, int *read_ptr)
{
	char	*buf;

	while (!found_newline(*stash) && *read_ptr != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
		{
			return (NULL);
		}
		*read_ptr = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && *read_ptr == 0) || *read_ptr == -1)
		{
			free(buf);
			return (0);
		}
		buf[*read_ptr] = '\0';
		stash = ft_strjoin(stash, buf, ft_strlen(stash), ft_strlen(buf));
		free(buf);
		extract_line(stash, read);
	}
}

// extrait tout les caractere de la stash et les stock dans la line
// stop apres le premier \n rencontrer
void	extract_line(char *stash, char *line)
{
	int	i;

	i = 0;
	gnerate_line(line, stash);
	if (*line == NULL)
	{
		return (NULL);
	}
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
	line[i] = '\0';
}

// apres avoir extrait stash dans line, plus besoin des caractere dans stash
// cette fonction clear la stash seulement les caractere non retourner
// a la fin de get_next_line() sont toujours dans la static stash
void	clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*last;
	char	*clean;

	last = ft_strlen(stash);
	i = 0;
	j = 0;
	clean = NULL;
	while (last[i] && last[i] != '\0')
	{
		i++;
		clean = malloc(sizeof(char) * (ft_strlen(last) - i) + 1);
		if (!clean)
			return (NULL);
	}
	while (last[i])
	{
		clean[j++] = last[i++];
	}
	clean[j] = '\0';
	free(stash);
	*stash = clean;
}
