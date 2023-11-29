# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 19:54:55 by cleguina          #+#    #+#              #
#    Updated: 2023/11/29 19:00:09 by cleguina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


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