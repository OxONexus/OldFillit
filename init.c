/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 07:15:31 by apaget            #+#    #+#             */
/*   Updated: 2015/12/06 17:19:53 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		init_tab(t_tetrimos *tab)
{
	int count;
	int	nb_bloc;

	nb_bloc = 0;
	count = 0;
	while (count < 26)
	{
		while (nb_bloc < 4)
		{
			tab[count].bloc[nb_bloc].x = -1;
			tab[count].bloc[nb_bloc].y = -1;
			nb_bloc++;
		}
		nb_bloc = 0;
		count++;
	}
}

void		initok(int *ok)
{
	int count;

	count = 0;
	while (count < 4)
	{
		ok[count] = 0;
		count++;
	}
}
