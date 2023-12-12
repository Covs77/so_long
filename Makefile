# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 19:54:55 by cleguina          #+#    #+#              #
#    Updated: 2023/12/12 19:39:15 by cleguina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m


# nombre programa

NAME = so_long

# compilador
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

LIB = ar rcs


LIBFT_DIR = ./Libft
LIBFT_PATH		= $(LIBFT_DIR)/libft.a

LIBMLX_DIR = ./MLX42
LIBMLX_PATH = $(LIBMLX_DIR)/libmlx42.a

LIB_SYS		:= -Iinclude -lglfw -L "/Users/cleguina/.brew/opt/glfw/lib/"

SRC = so_long.c so_long_parse.c so_long_read_map.c so_long_utils.c so_long_check_map.c \
so_long_game.c so_long_utils_2.c so_long_playable.c so_long_playground.c
OBJS = $(SRC:.c=.o)

#BOBJS = $(BONUS:.c=.o)1




# Compila la libreria libft. -C se utiliza para cambiar de directorio



$(NAME): $(LIBFT_PATH) $(LIBMLX_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) $(LIB_SYS) $(LIBMLX_PATH)  -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH):
			@make -s -C $(LIBFT_DIR)

$(LIBMLX_PATH):
			@make -s -C $(LIBMLX_DIR)



# Agrega los archivos objeto a la lista de archivos secundarios
all: $(NAME)

clean:
			@rm -f $(OBJS)
# @echo "$(GREEN)$(BOLD)Done.$(RESET)"
			@make clean -s -C $(LIBMLX_DIR)
			@make clean -s -C $(LIBFT_DIR)
			
#	$(MAKE) -C $(LIBFT_DIR) $(LIBMLX_DIR) clean
#	rm -f $(OBJS)


fclean: clean
	@make fclean -s -C $(LIBMLX_DIR)
	@make fclean -s -C $(LIBFT_DIR)
	rm -f $(NAME)

#	$(MAKE) -C $(LIBFT_DIR) $(LIBMLX_DIR) fclean
#	rm -f $(NAME)

re: fclean all


# bonus: $(NAME) $(BOBJS)
#	@ar rcs $(NAME) $(BOBJS)
	
.PHONY: re all clean fclean 