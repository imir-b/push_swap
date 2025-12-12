# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlad <vlad@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 11:14:33 by vbleskin          #+#    #+#              #
#    Updated: 2025/12/12 17:51:21 by vlad             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# EXE
NAME		= push_swap
NAME_BONUS	= checker

# DIR
LIBFT_DIR	= ./libft
SRC_DIR		= ./srcs
BONUS_DIR	= ./bonus
GNL_DIR		= $(BONUS_DIR)/gnl

# SRC
SRC_COMMON	= $(SRC_DIR)/parsing.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/stack_utils.c \
			$(SRC_DIR)/errors.c \
			$(SRC_DIR)/swap.c \
			$(SRC_DIR)/push.c \
			$(SRC_DIR)/rotate.c \
			$(SRC_DIR)/reverse_rotate.c
SRC_PS		= $(SRC_DIR)/main.c \
			$(SRC_DIR)/algo.c \
			$(SRC_DIR)/algo_find_node.c \
			$(SRC_DIR)/algo_get_cost.c
SRC_BONUS	= $(BONUS_DIR)/checker.c \
			$(GNL_DIR)/get_next_line.c \
			$(GNL_DIR)/get_next_line_utils.c

# OBJ
OBJ_COMMON	= $(SRC_COMMON:.c=.o)
OBJ_PS		= $(SRC_PS:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

# LIB
LIBFT		= $(LIBFT_DIR)/libft.a

# COMPIL
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I includes -I $(LIBFT_DIR) -I $(GNL_DIR) -D BUFFER_SIZE=10
RM			= rm -f

# RULES
all:		$(NAME)

$(LIBFT):
			make -C $(LIBFT_DIR)

$(NAME):	$(OBJ_COMMON) $(OBJ_PS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ_COMMON) $(OBJ_PS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus:		$(OBJ_COMMON) $(OBJ_BONUS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ_COMMON) $(OBJ_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ_COMMON) $(OBJ_PS) $(OBJ_BONUS)
			make -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME) $(NAME_BONUS)
			make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re bonus