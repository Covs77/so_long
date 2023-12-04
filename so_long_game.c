/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:15:04 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/04 21:06:26 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void ft_map_size(t_board *board, char **map)
{
	board->x = ft_strlen(map[0]);
	board->y = ft_matrix_lines(map);
	printf("x: %d\n", board->x);
	printf("y: %d\n", board->y);
}



void init_board(t_board *board)
{
	
	board->map = NULL;
	board->x = 0;
	board->y = 0;
	
	
}

void ft_game (t_board *board)
{
	t_board *board;
	//// inicializar el juego, falta chequear si es jugable.
}