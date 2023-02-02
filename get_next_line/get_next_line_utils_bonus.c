/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste <ccoste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:37:07 by ccoste            #+#    #+#             */
/*   Updated: 2022/12/15 14:37:09 by ccoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cherche caractere retour a la ligne dans chaines de caractere
int	found_newline(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
	{
		return (0);
	}
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

// compte une chaine de caractere
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// copie une chaine de caractere dans une autre
char	*ft_strjoin(char *stash, char *buf)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	if (!stash || !buf)
		return (NULL);
	dest = ft_calloc(((ft_strlen(stash) + ft_strlen(buf)) + 1), sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	if (stash)
	{
		while (stash[++i] != '\0')
			dest[i] = stash[i];
	}
	while (buf[j])
		dest[i++] = buf[j++];
	free(stash);
	return (dest);
}

int	generate_line(char *stash)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			len++;
			break ;
		}
		len++;
		i++;
	}
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*str;
	unsigned int	i;

	if (size != 0 && (size * nmemb) / size != nmemb)
		return (NULL);
	str = malloc(nmemb * size);
	if (!nmemb || !size)
		return (str);
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (i < (size * nmemb))
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
