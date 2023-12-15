/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_it.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:38:52 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/15 21:09:32 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move(t_board *b, t_point pos,int x,int y)
{
		b->map[pos.y][pos.x] = '0';
		b->map[pos.y + y][pos.x + x] = 'P';
		b->moves++;	
}
// Añadir atexit(ft_l); antes del exit para checkear leaks

static void	ft_move_to_exit(t_board *b, t_point pos, int x, int y)
{
	if (b->collect == 0)
	{		
		b->map[pos.y][pos.x] = '0';
		b->map[pos.y + y][pos.x + x] = 'P';
		ft_draw_playground(b, b->map);
		b->moves++;
		ft_print_moves(b->moves);
		ft_free_matrix(b->map);
		exit(0);
	}
	
}
/* void ft_draw_pos(t_board *board, t_point pos)
{
	ft_draw_map(board, board->map, pos.y, pos.x);
	
} */
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

	//ft_draw_playground(b, b->map);
	if (b->map[pos.y + y][pos.x + x] == 'E')
		ft_move_to_exit (b, pos, x, y);
	if (b->moves != mv)
		ft_print_moves(b->moves);
}


