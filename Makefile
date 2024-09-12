# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 08:03:09 by hlachhab          #+#    #+#              #
#    Updated: 2024/06/27 08:03:50 by hlachhab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX = ./MLX42/build
LIBFT = ./utils/libft
PRINTF = ./utils/printf


DFLAGS = $(MLX)/libmlx42.a -Iinclude -Ofast -lglfw -L"/Users/hlachhab/.brew/opt/glfw/lib/"
LIBS = $(MLX)/libmlx42.a $(LIBFT)/libft.a $(PRINTF)/libftprintf.a
HEADER = -I ./includes -I ./MLX42/include -I $(LIBFT) -I $(PRINTF)
# FLAGS = -framework Cocoa -framework OpenGL -framework IOKit

CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRC = so_long.c \
		map.c load_game.c \
		check_game.c check_game1.c \
		valid_path.c key_hook.c collect_food.c\

OBJ = $(SRC:.c=.o)

all: mlx libft printf $(NAME)

mlx:
	@$(MAKE) -C $(MLX)

libft:
	@$(MAKE) -C $(LIBFT)

printf:
	@$(MAKE) -C $(PRINTF)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJ) 
	$(CC) $(DFLAGS) $(FLAGS) $(OBJ) $(LIBS) $(HEADRS) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(PRINTF) clean
	

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(PRINTF) fclean

re: fclean all
