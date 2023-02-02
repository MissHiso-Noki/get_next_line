/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste <ccoste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:49:03 by ccoste            #+#    #+#             */
/*   Updated: 2022/12/15 14:18:23 by ccoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*read_and_stash(int fd, char *stash, int rd_bytes);
char	*extract_line(char *stash);
char	*clean_stash(char *stash);
char	*calloc_extract_line(char *line, char *stash);

int		found_newline(char *stash);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		generate_line(char *stash);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
