# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 01:28:41 by vbleskin          #+#    #+#              #
#    Updated: 2026/01/05 01:42:24 by vbleskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# EXE
# ------------------------------------------------------------------------------

NAME            =   push_swap
NAME_BONUS      =   checker

# ------------------------------------------------------------------------------
# DIR
# ------------------------------------------------------------------------------

LIBFT_DIR       =   libft
SRC_DIR         =   srcs
BONUS_DIR       =   bonus
OBJ_DIR         =   objs

# ------------------------------------------------------------------------------
# SRC
# ------------------------------------------------------------------------------

SRC_COMMON      =   $(SRC_DIR)/parsing.c \
                    $(SRC_DIR)/utils.c \
                    $(SRC_DIR)/stack_utils.c \
                    $(SRC_DIR)/errors.c \
                    $(SRC_DIR)/swap.c \
                    $(SRC_DIR)/push.c \
                    $(SRC_DIR)/rotate.c \
                    $(SRC_DIR)/reverse_rotate.c \
                    $(SRC_DIR)/algo.c \
                    $(SRC_DIR)/algo_find_node.c \
                    $(SRC_DIR)/algo_get_cost.c

SRC_PS			=	$(SRC_DIR)/main.c

SRC_BONUS       =   $(BONUS_DIR)/checker.c

# ------------------------------------------------------------------------------
# OBJ
# ------------------------------------------------------------------------------

OBJ_COMMON      =   $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_COMMON))
OBJ_PS			=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_PS))
OBJ_BONUS       =   $(patsubst $(BONUS_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_BONUS))

# ------------------------------------------------------------------------------
# LIB
# ------------------------------------------------------------------------------

LIBFT			=	$(LIBFT_DIR)/libft.a

# ------------------------------------------------------------------------------
# COMPIL
# ------------------------------------------------------------------------------

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -I includes -I $(LIBFT_DIR)/includes -D BUFFER_SIZE=10
MAKEFLAGS       +=	--no-print-directory
RM				=	rm -rf

# ------------------------------------------------------------------------------
# RULES
# ------------------------------------------------------------------------------

all:			$(NAME)

$(LIBFT):
				@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "Compiling $<"

$(OBJ_DIR)/%.o:	$(BONUS_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "Compiling bonus $<"

$(NAME):		$(OBJ_COMMON) $(OBJ_PS) $(LIBFT)
				@$(CC) $(CFLAGS) $(OBJ_COMMON) $(OBJ_PS) -L$(LIBFT_DIR) -lft -o $(NAME)
				@echo "$(NAME) compiled successfully"

bonus:          $(OBJ_COMMON) $(OBJ_BONUS) $(LIBFT)
				@$(CC) $(CFLAGS) $(OBJ_COMMON) $(OBJ_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)
				@echo "$(NAME_BONUS) compiled successfully"

clean:
				@$(RM) $(OBJ_DIR)
				@make -C $(LIBFT_DIR) clean
				@echo "$(OBJ_DIR) cleaned successfully"

fclean:         clean
				@$(RM) $(NAME) $(NAME_BONUS)
				@make -C $(LIBFT_DIR) fclean
				@echo "$(NAME) / $(NAME_BONUS) cleaned successfully"

re:             fclean all

.PHONY:         all clean fclean re bonus