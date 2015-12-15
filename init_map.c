/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 17:53:43 by apaget            #+#    #+#             */
/*   Updated: 2015/12/07 17:43:08 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		clear_map(char **map)
{
	int x;
	int y;
	int size;

	size = get_sizeof_map(map);
	x = 0;
	y = 0;
	while (x < size)
	{
		while (y < size)
		{
			map[x][y] = '.';
			y++;
		}
		y = 0;
		x++;
	}
}

int			get_numberof_tetrimos(t_tetrimos *tab)
{
	if (tab->bloc[0].x == -1)
		return (0);
	else
		return (get_numberof_tetrimos(tab + 1) + 1);
}

int			best_size(int nb_of_tetrimos)
{
	int bst_size;

	nb_of_tetrimos *= 4;
	bst_size = 2;
	while (bst_size * bst_size < nb_of_tetrimos)
		bst_size++;
	return (bst_size - 1);
}

char		**get_init_tab(t_tetrimos *tab)
{
	int		count;
	int		count2;
	int		size;
	char	**map;

	count = 0;
	count2 = 0;
	size = best_size(get_numberof_tetrimos(tab));
	if (!(map = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	while (count < size)
	{
		if (!(map[count] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		while (count2 < size)
		{
			map[count][count2] = '.';
			count2++;
		}
		map[count][count2] = '\0';
		count2 = 0;
		count++;
	}
	return (map);
}
