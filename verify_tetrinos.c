/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_tetrinos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 07:13:04 by apaget            #+#    #+#             */
/*   Updated: 2015/12/07 17:24:34 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_char(char c, int x, int nb)
{
	if (c != '#' && c != '.' && c != '\n')
		return (0);
	if (x % 5 > 4 || x / 5 > 4)
		return (0);
	if ((c == '\n' && x % 5 != 0) || (c == '\0' && x != 20))
		return (0);
	if (nb > 4)
		return (0);
	return (1);
}

int			check_valid_t_tetrimos(t_tetrimos *tab)
{
	int count;
	int ok;

	count = 25;
	ok = 0;
	while (tab[count].bloc[0].x < 0)
		count--;
	while (count >= 0)
	{
		if (check_one_tetrinos(tab[count]) == 0)
			return (0);
		count--;
	}
	return (1);
}

int			check_one_tetrinos(t_tetrimos test)
{
	int count;
	int ok[4];

	count = 0;
	initok(ok);
	next_bloc(test.bloc[0].x, test.bloc[0].y, test, ok);
	while (count < 4)
	{
		if (ok[count] != 1)
			return (0);
		count++;
	}
	return (1);
}

void		next_bloc(int x, int y, t_tetrimos test, int tab[])
{
	int count;

	count = 0;
	while (count < 4)
	{
		if ((test.bloc[count].x == x && test.bloc[count].y == y)
				&& tab[count] != 1)
		{
			tab[count] = 1;
			next_bloc(x, y + 1, test, tab);
			next_bloc(x + 1, y, test, tab);
			next_bloc(x, y - 1, test, tab);
			next_bloc(x - 1, y, test, tab);
		}
		count++;
	}
}
