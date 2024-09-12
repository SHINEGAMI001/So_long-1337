# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 17:35:29 by hlachhab          #+#    #+#              #
#    Updated: 2024/06/25 20:08:49 by hlachhab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_putstr.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putnnbr.c \
		ft_puthexa.c \

OBJS = $(SRCS:%.c=%.o)

# PROGRAM = libftprintf

# LINKER = -L. -lftprintf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf



all: $(NAME)


$(NAME): 	$(OBJS)
		@-ar rcs $(NAME) $(OBJS)

# $(PROGRAM): $(OBJS) $(NAME)
# 		$(CC) $(CFLAGS) $(OBJS) -o $@ $(LINKER)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(OBJS) $(NAME)

re:			fclean all

