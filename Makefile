# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 11:14:33 by vbleskin          #+#    #+#              #
#    Updated: 2025/12/09 14:22:38 by vbleskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		$(wildcard ./srcs/*.c)
OBJ =		$(SRC:.c=.o)

LIBFT_DIR =	./libft
LIBFT =		$(LIBFT_DIR)/libft.a

CC =		cc
CFLAGS =	-Wall -Werror -Wextra -I includes -I $(LIBFT_DIR)
RM =		rm -f

NAME =		push_swap

all:		$(NAME)

$(LIBFT):
			make -C $(LIBFT_DIR)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ)
			make -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re