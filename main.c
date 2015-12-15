/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 07:25:33 by apaget            #+#    #+#             */
/*   Updated: 2015/12/15 16:38:48 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_tetrimos		*tab;
	char			**map;
	char			**soluce;

	if (argc == 2)
	{
		tab = get_tab_t_tetrimos(argv[1]);
		if (!tab)
		{
			ft_putstr("error\n");
			return (0);
		}
		if (!(map = get_init_tab(tab)))
			return (0);
		t_vector_t_tetrimos(tab);
		while (!(soluce = recur_solve(&tab[0], map, 'A')))
		{
			map = extend_map(map, get_sizeof_map(map));
			clear_map(map);
		}
		print_map(soluce);
	}
	else
		ft_putstr("bad number of arguments ...");
	return (0);
}
