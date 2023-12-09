/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_playable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:39:46 by cova              #+#    #+#             */
/*   Updated: 2023/12/09 14:56:51 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(char **map)
{	
	int		i;
	char	**map_copy;

	i = 0;
	map_copy = malloc(sizeof(char *) * (ft_strlen(map[i]) + 1));
	if (map_copy == NULL)
	{
		ft_free_matrix(map_copy);
		ft_error(6);
	}
	while (map[i] != NULL)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			ft_free_matrix(map_copy);
			ft_error(9);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	ft_way_out(char **map, t_point pos)
{
	if (map[pos.y][pos.x] != '.')
	{
		ft_free_matrix(map);
		ft_error(10);
	}
}

void	ft_collect_all(char **map_copy, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL && map_copy[i] != NULL)
	{
		while (map[i][j] != '\0' && map_copy[i][j] != '\0')
		{
			if (map[i][j] != 'C')
				j++;
			else if (map[i][j] == 'C' && map_copy[i][j] == '.')
				j++;
			else
			{
				ft_free_matrix(map);
				ft_free_matrix(map_copy);
				ft_error(10);
			}
		}
		j = 0;
		i++;
	}
}

void	ft_playable_map(char **map)
{
	t_point	*pos_player;
	t_point	*pos_exit;
	t_point	*size;
	char	**map_copy;

	map_copy = ft_copy_map(map);
	pos_player = NULL;
	pos_exit = NULL;
	size = NULL;
	ft_init_pos (&pos_player);
	ft_init_pos (&pos_exit);
	ft_init_pos (&size);
	ft_find_map(map, 'P', pos_player);
	ft_find_map(map, 'E', pos_exit);
	size->x = ft_strlen(map[0]);
	size->y = ft_matrix_lines(map);
	flood_fill (map_copy, *size, *pos_player);
	ft_way_out(map_copy, *pos_exit);
	ft_collect_all(map_copy, map);
	ft_free_matrix (map_copy);
	free (size);
	free (pos_player);
	free (pos_exit);
}

void	flood_fill(char **map, t_point size, t_point pos)
{
	if (pos.x < 0 || pos.x >= size.x || \
		pos.y < 0 || pos.y >= size.y || \
		map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == '.')
		return ;
	map[pos.y][pos.x] = '.';
	flood_fill(map, size, (t_point){pos.x - 1, pos.y});
	flood_fill(map, size, (t_point){pos.x + 1, pos.y});
	flood_fill(map, size, (t_point){pos.x, pos.y - 1});
	flood_fill(map, size, (t_point){pos.x, pos.y + 1});
}
