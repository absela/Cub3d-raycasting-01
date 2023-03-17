# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absela <absela@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 01:46:46 by absela            #+#    #+#              #
#    Updated: 2023/03/17 05:31:01 by absela           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS = cub3d.c init.c need_to_remov.c util_mlx.c move_player.c map2d.c raycast1.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

.%c.%o: cub3d.h
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	cd libft && make
	cd ..
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	cd libft && make fclean
	cd ..
	$(RM) $(NAME)

re: fclean all