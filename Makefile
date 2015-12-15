# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apaget <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 17:20:54 by apaget            #+#    #+#              #
#    Updated: 2015/12/09 15:12:19 by apaget           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILESRC = get_tetrimos.c	\
		  init.c			\
		  main.c			\
		  solve_tetrimos.c	\
		  vector.c			\
		  init_map.c		\
		  gestion_map.c		\
		  gestion_map2.c	\
		  display_fct.c		\
		  verify_tetrinos.c

GREY=$'\x1b[30m'
RED=$'\x1b[31m'
GREEN=$ \x1b[32m
YELLOW=$'\x1b[33m'
BLUE=$'\x1b[34m'
PURPLE=$'\x1b[35m'
CYAN=$'\x1b[36m'
WHITE=$'\x1b[37m'

SRCOBJ = $(FILESRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm

NAME = fillit
all : $(NAME)

$(NAME) : $(SRCOBJ)
	$(CC) $(SRCOBJ) -o $(NAME)
	@echo "${GREEN}Binary have been created"

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $^ $(FLAGS)

clean:
	$(RM) $(SRCOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
