/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_playable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:39:46 by cova              #+#    #+#             */
/*   Updated: 2023/12/15 18:40:22 by cleguina         ###   ########.fr       */
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
	
	ft_init_pos (&pos_player);
	ft_init_pos (&pos_exit);
	ft_init_pos (&size);
	ft_find_map(map, 'P', pos_player);
	ft_find_map(map, 'E', pos_exit);
	size->x = ft_strlen(map[0]);
	size->y = ft_matrix_lines(map);
	if (size->x == size->y)
	{
		ft_free_matrix(map);
		ft_error(5);
	}
	ft_check_out(map, size, pos_player, pos_exit);
	free (size);
	free (pos_player);
	free (pos_exit);
}

void	flood_fill(char **map, t_point size, t_point pos)
{
	if (pos.x < 0 || pos.x >= size.x || \
		pos.y < 0 || pos.y >= size.y || map[pos.y][pos.x] == 'E'|| \
		map[pos.y][pos.x] == '1'|| \
		map[pos.y][pos.x] == '.')
		return ;
	map[pos.y][pos.x] = '.';
	flood_fill(map, size, (t_point){pos.x - 1, pos.y});
	flood_fill(map, size, (t_point){pos.x + 1, pos.y});
	flood_fill(map, size, (t_point){pos.x, pos.y - 1});
	flood_fill(map, size, (t_point){pos.x, pos.y + 1});
}

void	flood_fill_2(char **map, t_point size, t_point pos)
{
	if (pos.x < 0 || pos.x >= size.x || \
		pos.y < 0 || pos.y >= size.y || \
		map[pos.y][pos.x] == '1' || \
		map[pos.y][pos.x] == '.')
		return ;
	map[pos.y][pos.x] = '.';
	flood_fill_2(map, size, (t_point){pos.x - 1, pos.y});
	flood_fill_2(map, size, (t_point){pos.x + 1, pos.y});
	flood_fill_2(map, size, (t_point){pos.x, pos.y - 1});
	flood_fill_2(map, size, (t_point){pos.x, pos.y + 1});
}


