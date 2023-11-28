# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 19:54:55 by cleguina          #+#    #+#              #
#    Updated: 2023/11/28 21:31:14 by cleguina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# nombre programa

NAME = so_long

# compilador
CC = gcc
# Opciones de compilación
CFLAGS = -g -Wall -Werror -Wextra

# Crea una biblioteca estática utilizando (ar)
# ar -> crea biblioteca
# r -> remplaza o agrega archivos a la biblioteca
# c -> crea biblioteca si no existe
# s -> agrega información de índice a la biblioteca, para acceder más rapido
LIB = ar rcs

# Define la ruta al directorio donde se encuentra libft
LIBFT_DIR = ./Libft
GNL_DIR = ./Get_next_line

# Ruta completa al archivo de la libreria libft.a
LIBFT = $(LIBFT_DIR)/libft.a
GNL = $(GNL_DIR)/get_next_line.a

# Define el archivo fuente del programa push_swap
# Agrega aquí todos tus archivos fuente

SRC = so_long.c

	
# Define los archivos objeto generados a partir de los fuente

OBJS = $(SRC:.c=.o)

# .SECONDARY: $(OBJS)

BOBJS = $(BONUS:.c=.o)

# Agrega los archivos objeto a la lista de archivos secundarios
all: $(NAME) $(LIBFT) $(GNL)

# Compila la libreria libft. -C se utiliza para cambiar de directorio
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)


# Se utiliza el compilador (CC) con las opciones (CFLAGS) para crear
# el programa (NAME) a partir de los archivos objetos ($^)
# Especificando la ubicación de la libreria (LIBFT_DIR) y se enlaza (lft)
# -o especifica el nombre del archivo de salida
# $@ se refiere al objetivo de la regla, nombre del programa (NAME)
# "-o $@" establece el nombre del archivo de salida como el nombre del programa

# Se utiliza el compilador (CC) con las opciones (CFLAGS) para crear
# el programa (NAME) a partir de los archivos objetos ($^)
# Especificando la ubicación de la libreria (LIBFT_DIR) y se enlaza (lft)
# -o especifica el nombre del archivo de salida
# $@ se refiere al objetivo de la regla, nombre del programa (NAME)
# "-o $@" establece el nombre del archivo de salida como el nombre del programa
$(NAME): $(LIBFT) $(GNL) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) $(GNL) -lft -I so_long.h


# Regla para compilar todos los archivos fuentes .c en archivos objetos .o
# Se utiliza el compilador (CC) con las flags (CFLAGS) para compilar cada archivo
# fuente ($<) en su archivo objeto ($@). Se especifica la ubicación de los archivos
# de inclusión de la libreria libft (-I$(LIBFT_DIR))


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(LIBFT_DIR) $(GNL_DIR)

# utiliza el comando  make  para ejecutar la regla  clean  en el directorio de la
# librería libft. Esto se utiliza para limpiar los archivos objeto generados 
# durante la compilación de la librería. 
# rm -f $(OBJS) : Aquí se utiliza el comando  rm  para eliminar los archivos objeto generados.

clean:
	$(MAKE) -C $(LIBFT_DIR) $(GNL) clean
	rm -f $(OBJS)

# Esta línea establece la regla  fclean  como una dependencia de la regla  clean 
# Esto significa que al ejecutar  make fclean , primero se ejecutará  make clean 
# se utiliza el comando  make  para ejecutar la regla  fclean  en el directorio de la librería libft
# tiliza para limpiar los archivos generados durante la compilación de la librería.
# utiliza el comando  rm  para eliminar el programa generado
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) $(GNL) fclean
	rm -f $(NAME)


# al ejecutar  make re , primero se ejecutará  make fclean  y luego  make all .
re: fclean all

bonus: $(NAME) $(BOBJS)
	@ar rcs $(NAME) $(BOBJS)
	
.PHONY: re all clean fclean 