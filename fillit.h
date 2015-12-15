/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 01:26:26 by apaget            #+#    #+#             */
/*   Updated: 2015/12/07 17:24:17 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <string.h>
# include <unistd.h>

# define BUF_SIZE 20
# define SIZE 2

typedef struct	s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct	s_tetrimos
{
	t_vector	bloc[4];
}				t_tetrimos;

int				get_sizeof_map(char **map);
void			print_all_tetrimos(t_tetrimos *tab);
int				valid_pos(char **map, t_tetrimos form, t_vector index);
void			print_tetrimos(t_tetrimos tmp);
void			free_map(char **map);
void			clear_map(char **map);
char			*get_blank_line(int size);
char			**get_init_tab(t_tetrimos *tab);
char			**save_map(char **map);
char			**recur_solve(t_tetrimos *add, char **map, char c);
void			ft_putstr(char *str);
char			*ft_strcpy(char *str);
void			print_map(char **map);
void			initok(int *ok);
t_tetrimos		*get_tab_t_tetrimos(char *str);
void			remove__to_map(char **map, t_vector pos, t_tetrimos tmp);
int				check_one_tetrinos(t_tetrimos test);
void			t_vector_t_tetrimos(t_tetrimos *tab);
int				check_valid_t_tetrimos(t_tetrimos *tab);
int				add_to_tab(t_tetrimos *tab, int fd);
void			add_to_map(char **map, t_vector pos, t_tetrimos tmp, char c);
int				get_tetrimo(char *buffer, t_tetrimos *to_fill);
t_vector		find_next_valid_pos(t_tetrimos form, char **map,
				t_vector index);
int				check_char(char c, int x, int nb);
char			**extend_map(char **map, int size);
void			init_tab(t_tetrimos *tab);
void			next_bloc(int x, int y, t_tetrimos test, int tab[]);

#endif
