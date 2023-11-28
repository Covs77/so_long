# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 18:32:30 by cleguina          #+#    #+#              #
#    Updated: 2023/06/10 13:47:04 by cleguina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = get_next_line.c 


OBJ = $(SRC:.c=.o)

HDR = get_next_line.h 

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)

re: fclean all
	
.PHONY: re all clean fclean 
