# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 14:06:12 by tursescu          #+#    #+#              #
#    Updated: 2024/09/06 09:46:56 by tursescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/main.c src/utils.c src/map_checks.c src/init_utils.c\
		src/map_checks_utils.c src/free_utils.c src/initialisation.c\
		src/hook_actions.c src/pretty_terminal.c src/move.c

CC = @cc
RM = @rm -f
LIBFT_DIR = dirs/libft
MLX_DIR = dirs/mlx
CFLAGS =  -g -Wall -Werror -Wextra -Iinclude/mlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
# here to add libs from gnl
LIBS = $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a
OBJS =	$(SRCS:.c=.o)
NAME = so_long
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBS) -o $(NAME)	

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_DIR)/libmlx.a

re: fclean all

.PHONY: all libft clean fcelan re