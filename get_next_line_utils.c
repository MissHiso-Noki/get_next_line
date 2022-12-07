/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste < ccoste@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:13:09 by ccoste            #+#    #+#             */
/*   Updated: 2022/12/07 15:51:01 by ccoste           ###   ########.fr       */
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
		else
		{
			return (0);
		}
		i++;
	}

}

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
