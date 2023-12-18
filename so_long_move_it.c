/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_it.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:38:52 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/18 17:09:32 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move(t_board *b, t_point pos, int x, int y)
{
	b->map[pos.y][pos.x] = '0';
	b->map[pos.y + y][pos.x + x] = 'P';
	b->moves++;
}
// Añadir atexit(ft_l); antes del exit para checkear leaks

void	ft_key_hook_exit(mlx_key_data_t keydata, void *b)
{
	t_board	*board;

	board = b;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		write(1, "\nYou win!\n", 10);
		mlx_terminate(board->mlx);
		ft_free_matrix(board->map);
		exit(0);
	}
}

void	ft_end_game(t_board *b)
{
	mlx_key_hook(b->mlx, &ft_key_hook_exit, b);
}

static void	ft_move_to_exit(t_board *b, t_point pos, int x, int y)
{
	if (b->collect == 0)
	{
		b->map[pos.y][pos.x] = '0';
		b->map[pos.y + y][pos.x + x] = 'P';
		ft_draw_playground(b, b->map);
		b->moves++;
		ft_print_moves(b->moves);
		ft_end_game(b);
		mlx_loop(b->mlx);
		write(1, "\nYou win!\n", 10);
		exit(0);
	}
}

void	ft_move_player(t_board *b, int x, int y)
{
	t_point	pos;
	int		mv;

	mv = b->moves;
	ft_find_map(b->map, 'P', &pos);
	if (b->map[pos.y + y][pos.x + x] == '0')
	{
		ft_draw_map(b, b->map, pos.y, pos.x);
		ft_move(b, pos, x, y);
	}
	if (b->map[pos.y + y][pos.x + x] == 'C')
	{
		ft_draw_map(b, b->map, pos.y, pos.x);
		ft_move(b, pos, x, y);
		b->collect--;
	}
	ft_draw_play_ex(b, b->map, pos.y + y, pos.x + x);
	if (b->map[pos.y + y][pos.x + x] == 'E')
		ft_move_to_exit (b, pos, x, y);
	if (b->moves != mv)
		ft_print_moves(b->moves);
}
