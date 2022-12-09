/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste <ccoste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:13:09 by ccoste            #+#    #+#             */
/*   Updated: 2022/12/08 13:57:07 by ccoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// cherche caractere retour a la ligne dans chaines de caractere
int	found_newline(char *stash)
{
	int	i;

	i = 0;
	if (stash == NULL)
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
char	*ft_strjoin(char const *s1, char const *s2, int size1, int size2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = malloc((size1 + size2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dest[size1 + j] = s2[j];
		j++;
	}
	dest[size1 + j] = '\0';
	return (dest);
}
