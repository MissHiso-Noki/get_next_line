/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste <ccoste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:49:03 by ccoste            #+#    #+#             */
/*   Updated: 2022/12/08 13:47:04 by ccoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
void	read_and_stash(int fd, char **stash, int *read_ptr);
void	extract_line(char *stash, int read);

int		found_newline(char *stash);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2, int size1, int size2);

#endif
