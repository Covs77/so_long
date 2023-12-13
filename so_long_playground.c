/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_playground.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:11:14 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/13 20:55:44 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_tex(t_board *board)
{
	if (!board->tex.ply || !board->tex.floor || !board->tex.wall || !board->tex.co || !board->tex.ex)
	{
		ft_free_matrix(board->map);
		ft_error(5);
	}
}

static void	ft_clear_texture(t_board *b)
{
	mlx_delete_texture(b->tex.floor);
	mlx_delete_texture(b->tex.wall);
	mlx_delete_texture(b->tex.ply);
	mlx_delete_texture(b->tex.co);
	mlx_delete_texture(b->tex.ex);
}

void ft_load_board (t_board *board)
{
	board->tex.floor = mlx_load_png("./images/floor.png");
	board->tex.wall = mlx_load_png("./images/wall.png");
	board->tex.ply = mlx_load_png("./images/unicorn.png");
	board->tex.co = mlx_load_png("./images/nube.png");
	board->tex.ex = mlx_load_png("./images/exit.png");
	ft_check_tex(board);
	board->im.ply = mlx_texture_to_image(board->mlx, board->tex.ply);
	board->im.floor = mlx_texture_to_image(board->mlx, board->tex.floor);
	board->im.wall = mlx_texture_to_image(board->mlx, board->tex.wall);
	board->im.co = mlx_texture_to_image(board->mlx, board->tex.co);
	board->im.ex = mlx_texture_to_image(board->mlx, board->tex.ex);
	ft_clear_texture(board);
}

void	ft_accion_player(t_board *b)
{
	mlx_key_hook(b->mlx, &ft_key_hook, b);
}

void	ft_key_hook(mlx_key_data_t keydata, void *b)
{
	t_board	*copy_b;

	copy_b = (t_board *)b;
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

void ft_move_player(t_board *b, int x, int y)
{
	t_point	pos;

	ft_find_map(b->map, 'P', &pos);
	if (b->map[pos.y + y][pos.x + x] == '0')
	{
		b->map[pos.y][pos.x] = '0';
		b->map[pos.y + y][pos.x + x] = 'P';
		ft_draw_playground(b, b->map);
	}
	if (b->map[pos.y + y][pos.x + x] == 'C')
	{
		b->map[pos.y][pos.x] = '0';
		b->map[pos.y + y][pos.x + x] = 'P';
		ft_draw_playground(b, b->map);
		b->collect--;
	}
	if (b->map[pos.y + y][pos.x + x] == 'E' && b->collect == 0)
	{
		b->map[pos.y][pos.x] = '0';
		b->map[pos.y + y][pos.x + x] = 'P';
		ft_draw_playground(b, b->map);
		exit(0);
	}
} 