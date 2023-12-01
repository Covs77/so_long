# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cova <cova@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 19:54:55 by cleguina          #+#    #+#              #
#    Updated: 2023/12/01 19:50:06 by cova             ###   ########.fr        #
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



SRC = so_long.c

OBJS = $(SRC:.c=.o)

#BOBJS = $(BONUS:.c=.o)1




# Compila la libreria libft. -C se utiliza para cambiar de directorio



$(NAME): $(LIBFT_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH):
			@make -s -C $(LIBFT_DIR)



# Agrega los archivos objeto a la lista de archivos secundarios
all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)


fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME) $(BOBJS)
	@ar rcs $(NAME) $(BOBJS)
	
.PHONY: re all clean fclean 