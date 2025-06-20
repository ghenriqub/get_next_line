# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 12:09:16 by ghenriqu          #+#    #+#              #
#    Updated: 2025/05/30 12:48:18 by ghenriqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME = push_swap

# compiler and flags:
CC = cc
CFLAGS = -Wall -Wextra -Werror

# basic and additional files:
SRC = 	src/0-main.c \
		src/1-input_check.c \
		src/1-split.c \
		src/2-filling.c \
		src/2-indexation.c \
		src/3-push.c \
		src/3-reverse_rotate.c \
		src/3-rotate.c \
		src/3-swap.c \
		src/4-sort.c \
		src/4-sort_tiny.c \
		src/5-cost.c \
		src/5-do_move.c \
		src/5-position.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

# standard rule:
all: $(NAME)

# compile and create the lib:
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Let's go! Push_swap built."

# compile .o:
%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<..."

# clean files:
clean:
	@$(RM) $(OBJ)
	@echo "Object files gone!"

# clean everything, .o and libft.a:
fclean: clean
	@$(RM) $(NAME)
	@echo "Binary gone!"

# recompile all:
re: fclean all

.PHONY: all re clean fclean
