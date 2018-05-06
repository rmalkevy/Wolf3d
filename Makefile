# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 20:40:36 by rmalkevy          #+#    #+#              #
#    Updated: 2017/03/04 12:24:04 by rmalkevy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = determine_map_size.c \
		draw.c \
		free_allocated_memory.c \
		key.c \
		map_reader.c \
		mod_strsplit.c \
		window.c \
		main.c

OBJ = $(SRC:.c=.o)

CC = gcc

INC = ./

LIB = -L ./libft/ -lft
LIBMLX = -L ./minilibx/ -lft

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./libft/
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(LIBMLX) -lmlx -framework OpenGL -framework AppKit

%.o: %.c
		$(CC) -c $<

clean:
		make -C ./libft/ clean
		rm -rf $(OBJ)

fclean: clean
		make -C ./libft/ fclean
		rm -f $(NAME)

re: fclean all