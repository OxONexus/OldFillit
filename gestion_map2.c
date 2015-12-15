/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:09:11 by apaget            #+#    #+#             */
/*   Updated: 2015/12/07 17:23:59 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		add_to_map(char **map, t_vector pos, t_tetrimos tmp, char c)
{
	int index;

	index = 0;
	while (index < 4)
	{
		map[pos.x + tmp.bloc[index].x][pos.y + tmp.bloc[index].y] = c;
		index++;
	}
}

void		remove__to_map(char **map, t_vector pos, t_tetrimos tmp)
{
	int index;

	index = 0;
	while (index < 4)
	{
		map[pos.x + tmp.bloc[index].x][pos.y + tmp.bloc[index].y] = '.';
		index++;
	}
}

char		*get_blank_line(int size)
{
	int		count;
	int		count2;
	char	*tmp;

	count = 0;
	count2 = 0;
	tmp = (char*)malloc(sizeof(char) * size + 2);
	while (count2 < size)
	{
		tmp[count2] = '.';
		count2++;
	}
	tmp[count2] = '.';
	tmp[count2 + 1] = '\0';
	return (tmp);
}

char		*ft_strcpy(char *str)
{
	int		count;
	int		count2;
	char	*tmp;

	count = 0;
	count2 = 0;
	while (str[count])
		count++;
	tmp = (char*)malloc(sizeof(char) * count + 1);
	while (count2 < count)
	{
		tmp[count2] = str[count2];
		count2++;
	}
	tmp[count2] = '\0';
	return (tmp);
}
