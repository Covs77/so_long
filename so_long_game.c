/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:15:04 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/13 20:46:42 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

void	ft_map_size(t_board *board)
{
	board->dim.x = ft_strlen(board->map[0]);
	board->dim.y = ft_matrix_lines(board->map);
}

void	init_board(t_board *board)
{
	board->map = NULL;
	board->dim.x = 0;
	board->dim.y = 0;
	board->tex.ply = NULL;
	board->tex.floor = NULL;
	board->tex.wall = NULL;
	board->tex.co = NULL;
	board->tex.ex = NULL;
	board->im.ply = NULL;
	board->im.floor = NULL;
	board->im.wall = NULL;
	board->im.co = NULL;
	board->im.ex = NULL;
	board->collect = 0;
	board->mlx = NULL;
}

void ft_game (t_board *board)
{
	//t_image	*g_img;
	
	ft_map_size(board);
	board->mlx = mlx_init(board->dim.x * P, board->dim.y * P, "Rainbow Run", false);
	if (!board->mlx)
	{
		ft_free_matrix(board->map);
		ft_error(5);
	}
	ft_load_board(board);
	ft_draw_playground(board, board->map);
	ft_accion_player(board);
	//g_img = mlx_new_image(board->mlx, 128, 128);
	//mlx_loop_hook(board->mlx, g_img, board);
	mlx_loop(board->mlx);
	mlx_terminate(board->mlx);
}


 