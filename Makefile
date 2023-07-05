# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 13:32:42 by gifulvi           #+#    #+#              #
#    Updated: 2022/05/19 18:09:02 by gifulvi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = solong.c map.c keys.c imgs.c files.c coins.c moves.c utils.c waiter.c

HDRS = incl/solong.h

OBJ = $(SRC:.c=.o)

RM = rm -f

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
		@(test -f $(MLX)  && echo "\033[32mMLX already built\033[0m") || (make -C ./minilibx && mv minilibx/libmlx.dylib .)
		$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)

all: $(NAME)
	make clean

clean:
	${RM} $(OBJ)

fclean:
	${RM} $(NAME) ${OBJ}
	make -C ./mlx clean

re: fclean $(NAME)


.PHONY: all clean fclean re reb
