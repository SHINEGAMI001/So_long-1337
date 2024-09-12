# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 06:15:37 by hlachhab          #+#    #+#              #
#    Updated: 2024/06/25 20:08:11 by hlachhab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_strlen.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_strjoin.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		ft_tolower.c ft_toupper.c ft_memchr.c ft_putstr_fd.c

OBJS = $(SRCS:%.c=%.o)


CC = gcc

CFLAGS = -Wall -Wextra -Werror




all: $(NAME)

%.o: %.c libft.h
		@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): 	$(OBJS)
		@-ar rc $(NAME) $(OBJS)


clean :
		@rm -f $(OBJS)

fclean: 	clean 
		@$(RM) $(NAME)

re: 		fclean all
