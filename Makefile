# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 10:52:34 by vicalons          #+#    #+#              #
#    Updated: 2025/03/03 00:31:50 by vicalons         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
NAME = push_swap
GCC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
RM = rm -rf
AR = ar -rcs
MAKE = make -sC
MKDIR = mkdir -p

# libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LINKER = -lft -L $(LIBFT_DIR)

# Include
INCLUDE_DIR = include
INCLUDE_FLAG = -I$(INCLUDE_DIR) \
			-I$(LIBFT_DIR) \

INCLUDE = $(INCLUDE_DIR)/push_swap.h \
	   	$(LIBFT_DIR)/libft.h

# Source
SRC_DIR = src/
SRC_FILES = main.c \
	    utils_checkargv.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

# Object
OBJ_DIR = obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# Comand
all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@$(MAKE) $(LIBFT_DIR)

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(NAME): $(OBJ) Makefile
	@$(GCC) $(CFLAGS) $(OBJ) $(LINKER) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDE)
	@$(GCC) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean:
	@$(RM) $(NAME)
	@$(MAKE) $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
