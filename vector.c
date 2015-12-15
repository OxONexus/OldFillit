/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 07:30:46 by apaget            #+#    #+#             */
/*   Updated: 2015/12/07 17:43:46 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		move_t_tetrimos(t_tetrimos *add, t_vector min)
{
	int nb;

	nb = 0;
	while (nb < 4)
	{
		add->bloc[nb].x -= min.x;
		add->bloc[nb].y -= min.y;
		nb++;
	}
}

void		t_vector_t_tetrimos(t_tetrimos *tab)
{
	int			count;
	int			nb;
	t_vector	min;

	min.x = 99999;
	min.y = 99999;
	count = 0;
	nb = 0;
	while (count < 26 && tab[count].bloc[0].x != -1)
	{
		min.x = 99999;
		min.y = 99999;
		while (nb < 4)
		{
			if (tab[count].bloc[nb].x < min.x)
				min.x = tab[count].bloc[nb].x;
			if (tab[count].bloc[nb].y < min.y)
				min.y = tab[count].bloc[nb].y;
			nb++;
		}
		move_t_tetrimos(&tab[count], min);
		nb = 0;
		count++;
	}
}
