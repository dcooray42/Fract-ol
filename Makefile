# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcooray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 13:50:44 by dcooray           #+#    #+#              #
#    Updated: 2017/02/20 10:52:36 by dcooray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c \
		draw_fractal.c \
		draw_fractal_bis.c \
		mandelbrot.c \
		julia.c \
		multibrot.c \
		burning_ship.c \
		error.c \
		event.c \
		event_key_hook.c \
		event_key_hook_bis.c \
		event_mandel.c \
		event_julia.c \
		event_julia_bis.c \
		event_multi.c \
		event_burn.c \
		mlx_funct.c \
		zoom.c \
		tips.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

PATHFT = ./libft

INCLUDE = -I./includes

LIBFT = -L$(PATHFT) -lft

MLX = -L/usr/local/lib -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

all: libft.a $(NAME)

libft.a:
	make -C $(PATHFT)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(LIBFT) $(MLX) $(OBJ)

%.o: %.c
	gcc $(FLAGS) $(INCLUDE) -c $^

clean:
	/bin/rm -f $(OBJ)
	make -C $(PATHFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(PATHFT) fclean

re: fclean all
