/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 17:59:51 by apaget            #+#    #+#             */
/*   Updated: 2015/12/07 18:02:12 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			get_sizeof_map(char **map)
{
	int c;

	c = 0;
	while (map[0][c] != '\0')
		c++;
	return (c);
}

int			ft_isalpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char		**save_map(char **map)
{
	char	**tmp;
	int		c;
	int		size;

	size = get_sizeof_map(map);
	c = 0;
	tmp = (char**)malloc(sizeof(char*) * size + 1);
	while (c < size)
	{
		tmp[c] = ft_strcpy(map[c]);
		c++;
	}
	return (tmp);
}

void		free_map(char **map)
{
	int c;
	int size;

	if (!map)
		return ;
	size = get_sizeof_map(map);
	c = 0;
	while (c < size)
	{
		free(map[c]);
		c++;
	}
	free(map);
}

char		**extend_map(char **map, int size)
{
	char	**tmp;
	int		c;

	c = 0;
	tmp = (char**)malloc(sizeof(char*) * size + 1);
	while (c < size + 1)
	{
		tmp[c] = get_blank_line(size);
		c++;
	}
	free_map(map);
	return (tmp);
}
