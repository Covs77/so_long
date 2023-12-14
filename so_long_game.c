/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:15:04 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/14 21:10:45 by cleguina         ###   ########.fr       */
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
	board->moves = 0;
	board->flag = 0;
}
void	ft_key_hook(mlx_key_data_t keydata, void *b)
{
	t_board	*copy_b;

	copy_b = b;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_move_player(copy_b, 1, 0);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_move_player(copy_b, 0, -1);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_move_player(copy_b, -1, 0);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_move_player(copy_b, 0, 1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		ft_move_player(copy_b, 1, 0);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		ft_move_player(copy_b, 0, -1);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		ft_move_player(copy_b, -1, 0);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		ft_move_player(copy_b, 0, 1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
}

void	ft_accion_player(t_board *b)
{
	mlx_key_hook(b->mlx, &ft_key_hook, b);
}

void	ft_game(t_board *b)
{
	ft_map_size(b);
	b->mlx = mlx_init(b->dim.x * P, b->dim.y * P, "Rainbow Run", false);
	if (!b->mlx)
	{
		ft_free_matrix(b->map);
		ft_error(5);
	}
	ft_load_board(b);
	ft_draw_playground(b, b->map);
	ft_accion_player(b);
	mlx_loop(b->mlx);
	mlx_terminate(b->mlx);
}
