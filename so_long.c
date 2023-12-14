/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:34:57 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/14 20:16:50 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

/* void	ft_l(void)
{
	system("leaks -q so_long");
} */
void	ft_error(int error)
{
	if (error == 1)
		write(2, "Error: Wrong number of arguments\n", 33);
	if (error == 2)
		write(2, "Erro: Wrong file name\n", 22);
	if (error == 3)
		write(2, "Error: Can`t open file\n", 23);
	if (error == 4)
		write(2, "Error: The map is an empty file\n", 32);
	if (error == 5)
		write(2, "Error: Wrong map\n", 17);
	if (error == 6)
		write(2, "Error: Malloc error\n", 20);
	if (error == 7)
		write(2, "Error: Wrong number of player or exit\n", 38);
	if (error == 8)
		write(2, "Error: No collectibles\n", 24);
	if (error == 9)
		write(2, "Error: Copy map failure\n", 25);
	if (error == 10)
		write(2, "Error: No playable map\n", 23);
	if (error == 11)
		write(2, "Error: Can`t draw map\n", 22);
	exit(EXIT_FAILURE);
}

// Añadir atexit(ft_l); al final de main  para checkear leaks

int	main(int argc, char **argv)
{
	t_board	board;

	init_board(&board);
	board.map = ft_parse(argc, argv);
	ft_count_collect(&board);
	ft_game(&board);
	ft_free_matrix(board.map);
}
