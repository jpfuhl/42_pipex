# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 12:36:35 by jpfuhl            #+#    #+#              #
#    Updated: 2021/07/20 13:54:06 by jpfuhl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libft.a
SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_countdigits.c ft_memccpy.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c


.PHONY: all clean fclean re bonus

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES)
	ar -crs $(NAME) ft_*.o
	ar -t $(NAME)

bonus: $(NAME)
	$(CC) $(CFLAGS) $(BONUS)
	ar -crs $(NAME) ft_*.o
	ar -t $(NAME)

all: $(NAME) bonus

clean:
	rm -f *.o *~

fclean: clean
	rm -f $(NAME)

re: fclean all
