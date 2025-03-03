# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 13:26:02 by vicalons          #+#    #+#              #
#    Updated: 2025/03/03 02:41:17 by vicalons         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_isalpha.c \
      ft_isdigit.c \
      ft_isalnum.c \
      ft_isascii.c \
      ft_isprint.c \
      ft_toupper.c \
      ft_tolower.c \
      ft_strlen.c \
      ft_strlcpy.c \
      ft_strlcat.c \
      ft_strchr.c \
      ft_strrchr.c \
      ft_strncmp.c \
      ft_strnstr.c \
      ft_memset.c \
      ft_bzero.c \
      ft_memcpy.c \
      ft_memmove.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_atoi.c \
      ft_calloc.c \
      ft_strdup.c \
      ft_substr.c \
      ft_strjoin.c \
      ft_strtrim.c \
      ft_split.c \
      ft_itoa.c \
      ft_strmapi.c \
      ft_striteri.c \
      ft_putchar_fd.c \
      ft_putstr_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c \

BNSSRC = bonus/ft_lstnew.c \
	 bonus/ft_lstadd_front.c \
	 bonus/ft_lstsize.c \
	 bonus/ft_lstlast.c \
	 bonus/ft_lstadd_back.c \
	 bonus/ft_lstdelone.c \
	 bonus/ft_lstclear.c \
	 bonus/ft_lstiter.c \

GNLSRC = get_next_line.c \
	 get_next_line_utils.c \

PRINTFSRC = ft_printf.c \
	    printf_utils.c \

SRC_2 = milestone_2/ft_strcmp.c \
	milestone_2/ft_atof.c \
	milestone_2/ft_isfloat.c \

OBJ = $(SRC:.c=.o)
BNSOBJ = $(BNSSRC:.c=.o)
GNLOBJ = $(GNLSRC:.c=.o)
PRINTFOBJ = $(PRINTFSRC:.c=.o)
OBJ_2 = $(SRC_2:.c=.o)
all: $(NAME)

$(NAME): $(OBJ) $(BNSOBJ) $(GNLOBJ) $(PRINTFOBJ) $(OBJ_2)
	ar -rcs $(NAME) $(OBJ) $(GNLOBJ) $(PRINTFOBJ) $(OBJ_2)
#bonus: $(BNSOBJ)
#	@ ar -rcs $(NAME) $(BNSOBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(BNSOBJ) $(GNLOBJ) $(PRINTFOBJ) $(OBJ_2)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus
