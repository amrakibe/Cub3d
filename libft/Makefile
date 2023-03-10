# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 20:10:00 by hkaddour          #+#    #+#              #
#    Updated: 2023/02/26 13:04:38 by hkaddour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
HEADER = libft.h
CFLAGS = -Wall -Wextra -Werror -g
SRCS =	ft_atoi.c \
		ft_putnbr_fd.c \
		ft_strlen.c \
		ft_bzero.c \
 		ft_putstr_fd.c \
		ft_strmapi.c \
		ft_calloc.c \
		ft_memchr.c \
		ft_split.c \
		ft_strncmp.c \
		ft_isalnum.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strnstr.c \
		ft_isalpha.c \
		ft_memcpy.c \
		ft_strdup.c \
		ft_strrchr.c \
		ft_isascii.c \
		ft_memmove.c \
		ft_striteri.c \
		ft_strtrim.c \
		ft_isdigit.c \
		ft_memset.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_isprint.c \
		ft_putchar_fd.c \
		ft_strlcat.c \
		ft_tolower.c \
		ft_itoa.c \
		ft_putendl_fd.c \
		ft_strlcpy.c \
		ft_toupper.c \
		ft_strcmp.c \
		ft_strcspn.c \
		ft_error.c

OBJS = $(SRCS:.c=.o)
BGreen=\033[1;32m

all : $(NAME)

%.o: %.c $(HEADER)
	@/bin/echo -n "."
	@$(CC) $(CFLAGS) -c $^

$(NAME): $(OBJS)
	@ar -rc $@ $^

clean:
	@rm -rf $(OBJS)
	@rm -rf *.gch

fclean : clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
