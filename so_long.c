/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:34:57 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/12 19:31:20 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	ft_l(void)
{
	system("leaks so_long");
}

void	ft_error(int error)
{
	if (error == 1)
		perror("Error:\nWrong number of arguments\n");
	if (error == 2)
		perror("Error\nWrong file name\n");
	if (error == 3)
		perror("Error\nCan`t open file\n");
	if (error == 4)
		perror("Error\nEmpty file\n");
	if (error == 5)
		perror("Error\nWrong map (lines size)\n");
	if (error == 6)
		perror("Error\nMalloc error\n");
	if (error == 7)
		perror("Error\nWrong map(more than 1 e or p)\n");
	if (error == 8)
		perror("Error\nNo collectibles\n");
	if (error == 9)
		perror("Error\nCopy map failure\n");
	if (error == 10)
		perror("Error\nNo playable map\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_board	board;

	init_board(&board);
	board.map = ft_parse(argc, argv);
	
	ft_print_map(board.map);
	ft_game(&board);
	ft_free_matrix(board.map);
	atexit(ft_l);
}
