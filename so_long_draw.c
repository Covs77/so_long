/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:10:47 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/15 20:25:35 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_board *b, char **map, int i, int j)
{
	if (map[i][j] == '1')
	{
		if ((mlx_image_to_window(b->mlx, b->im.wall, \
		j * P, i * P)) < 0)
			ft_error(11);
	}
	else if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'P')
	{
		if ((mlx_image_to_window(b->mlx, b->im.floor, \
		j * P, i * P)) < 0)
			ft_error(11);
	}
	if (map[i][j] == 'C')
	{
		if ((mlx_image_to_window(b->mlx, b->im.co, j * P, i * P)) < 0)
			ft_error(11);
	}
}

void	ft_draw_play_ex(t_board *b, char **map, int i, int j)
{
	if (map[i][j] == 'P')
	{
		if ((mlx_image_to_window(b->mlx, b->im.ply, \
		j * P, i * P)) < 0)
			ft_error(11);
	}
	if (map[i][j] == 'E')
	{
		if ((mlx_image_to_window(b->mlx, b->im.ex, j * P, i * P)) < 0)
			ft_error(11);
	}
}

void	ft_draw_playground(t_board *board, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_draw_map(board, map, i, j);
			ft_draw_play_ex(board, map, i, j);
			j++;
		}
		i++;
	}
}
