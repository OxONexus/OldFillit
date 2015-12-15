/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetrimos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:40:47 by apaget            #+#    #+#             */
/*   Updated: 2015/12/15 16:25:23 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				valid_pos(char **map, t_tetrimos form, t_vector index)
{
	int nb;

	nb = 0;
	while (nb < 4)
	{
		if (form.bloc[nb].x + index.x >= get_sizeof_map(map) ||
				form.bloc[nb].y + index.y >= get_sizeof_map(map))
			return (0);
		if (map[form.bloc[nb].x + index.x][form.bloc[nb].y + index.y] != '.')
			return (0);
		nb++;
	}
	return (1);
}

t_vector		find_next_valid_pos(t_tetrimos form, char **map, t_vector index)
{
	int nb;
	int size;

	size = get_sizeof_map(map);
	nb = 0;
	index.y++;
	while (index.x < size)
	{
		while (index.y < size)
		{
			if (valid_pos(map, form, index))
				return (index);
			index.y++;
		}
		index.y = 0;
		index.x++;
	}
	index.x = -1;
	return (index);
}

void			init_var(t_vector *pos, int *ok)
{
	pos->x = 0;
	pos->y = -1;
	*ok = 0;
}

char			**recur_solve(t_tetrimos *add, char **map, char c)
{
	t_vector	pos;
	char		**e_map;
	int			ok;

	init_var(&pos, &ok);
	if (add->bloc[0].x == -1)
		return (map);
	while (pos.x != -1)
	{
		pos = find_next_valid_pos(*add, map, pos);
		if (pos.x != -1)
			ok = 1;
		if (pos.x == -1 && ok == 1)
			return (e_map);
		if (pos.x == -1 && ok == 0)
			return (NULL);
		add_to_map(map, pos, *add, c);
		if ((e_map = recur_solve(add + 1, map, c + 1)))
			return (e_map);
		remove__to_map(map, pos, *add);
	}
	return (NULL);
}
