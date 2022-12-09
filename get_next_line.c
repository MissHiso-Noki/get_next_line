/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste <ccoste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:51:03 by ccoste            #+#    #+#             */
/*   Updated: 2022/12/08 13:55:11 by ccoste           ###   ########.fr       */
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
	// 1 : lire ce qu'on a dans notre fichiers et le mettre dans stash
	read_and_stash(fd, &stash, &read);
	if (stash == NULL)
	{
		return (NULL);
	}
	// 2 : extraire de stash dans line
	// 3 : nettoyer la stash
	return (line);
}

// utilise read pour add characters dans la stash
void	read_and_stash(int fd, char **stash, int *read_ptr)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		return (NULL);
	}
	while (!found_newline(*stash) && *read_ptr != 0)
	{
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
void	extract_line(char *stash, int read)
{
	while ()
}
// apres avoir extrait stash dans read, plus besoin des caractere dans stash
// cette fonction clear la stash seulement les caractere non retourner a la fin de
// get_next_line() sont toujours dans la static stash
void	clean_stash()
