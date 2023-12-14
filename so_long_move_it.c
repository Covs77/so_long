/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_it.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:38:52 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/14 21:20:01 by cleguina         ###   ########.fr       */
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
	b->map[pos.y][pos.x] = '0';
	b->map[pos.y + y][pos.x + x] = 'P';
	ft_draw_playground(b, b->map);
	b->moves++;
	ft_print_moves(b->moves);
	ft_free_matrix(b->map);
	exit(0);
}
static void ft_over_exit(t_board *b, t_point pos,int x,int y)
{
	b->map[pos.y][pos.x] = '0';
	b->map[pos.y + y][pos.x + x] = 'P';
	ft_draw_playground(b, b->map);
	b->moves++;
	b->flag = 1;
	ft_print_moves(b->moves);
}
static void ft_paint_exit_back(t_board *b, t_point pos,int x,int y)
{
	b->map[pos.y][pos.x] = 'E';
	b->map[pos.y + y][pos.x + x] = 'P';
	ft_draw_playground(b, b->map);
	b->moves++;
	b->flag = 0;
	ft_print_moves(b->moves);
}

void	ft_move_player(t_board *b, int x, int y)
{
	t_point	pos;
	int		mv;
	
	mv = b->moves;
	ft_find_map(b->map, 'P', &pos);
	if (b->flag == 1)
		ft_paint_exit_back(b, pos, x, y);
	if (b->map[pos.y + y][pos.x + x] == '0')
		ft_move(b, pos, x, y);
	if (b->map[pos.y + y][pos.x + x] == 'C')
	{
		ft_move(b, pos, x, y);
		b->collect--;
	}
	ft_draw_playground(b, b->map);
	if (b->map[pos.y + y][pos.x + x] == 'E' && b->collect == 0)
		ft_move_to_exit (b, pos, x, y);
	else if (b->map[pos.y + y][pos.x + x] == 'E' && b->collect != 0)
		ft_over_exit(b, pos, x, y);
	if (b->moves != mv)
		ft_print_moves(b->moves);
}


