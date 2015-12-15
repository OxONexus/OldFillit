/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetrimos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 17:21:47 by apaget            #+#    #+#             */
/*   Updated: 2015/12/07 19:00:51 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				get_tetrimo(char *buffer, t_tetrimos *to_fill)
{
	int			count;
	int			nb;

	nb = 0;
	count = 0;
	while (buffer[count])
	{
		if (!check_char(buffer[count], count + 1, nb))
			return (0);
		if (buffer[count] == '#')
		{
			to_fill->bloc[nb].x = count / 5;
			to_fill->bloc[nb].y = count % 5;
			nb++;
		}
		count++;
	}
	if (nb != 4)
		return (0);
	return (1);
}

int				add_to_tab(t_tetrimos *tab, int fd)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		count;

	count = 0;
	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		if (get_tetrimo(buf, &tab[count]) == 0)
			return (0);
		ret = read(fd, buf, 1);
		if (ret)
		{
			if (buf[0] != '\n' && buf[0] != '\0')
				return (0);
		}
		count++;
	}
	return (1);
}

t_tetrimos		*get_tab_t_tetrimos(char *str)
{
	int			fd;
	t_tetrimos	*tab;

	if ((tab = (t_tetrimos*)malloc(sizeof(t_tetrimos) * 26)) == NULL)
		return (NULL);
	fd = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	init_tab(tab);
	if ((add_to_tab(tab, fd)) == 0)
		return (NULL);
	if (check_valid_t_tetrimos(tab) == (int)NULL)
		return (NULL);
	close(fd);
	return (tab);
}
