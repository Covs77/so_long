/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_playable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:39:46 by cova              #+#    #+#             */
/*   Updated: 2023/12/07 19:45:52 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_find_map(char **map, char c, t_point *pos)
{   
    
    int i;
    int j;
  
    i = 0;
    j = 0;
    while (map[i] != NULL)
    {
        while (map[i][j] != '\0')
        {
            if (map[i][j] == c)
            {
                pos->x = i;
                pos->y = j;
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}
char **ft_copy_map(char **map)
{	
	int i;
	char **map_copy;
	
	i = 0;
	map_copy = malloc(sizeof(char *) * (ft_strlen(map[i]) + 1));
	if (map_copy == NULL)
	{
		free(map_copy);
		ft_error(6);
	}
	while (map[i] != NULL)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
			ft_error(9);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void ft_playable_map(char **map)
{
    t_point *pos_player = NULL;
	t_point *pos_exit = NULL;
	t_point *size = NULL;
    char **map_copy;
	    
	map_copy = ft_copy_map(map);
			
	ft_init_pos (&pos_player);
	ft_init_pos (&pos_exit);
	ft_init_pos (&size);
	ft_find_map(map, 'P', pos_player);
	ft_find_map(map, 'E', pos_exit);
	size->x = ft_strlen(map[0]);
	size->y = ft_matrix_lines(map);
	ft_print_pos(*pos_player);
	ft_print_pos(*pos_exit);
	ft_print_pos(*size);
	flood_fill (map_copy, *size, *pos_player);
	// Cuando acabe de comprobar
	free (size);
	free (pos_player);
	free (pos_exit);
     
}

/* void	flood_fill(char **map, t_point size, t_point pos)
{
	if (curr.x < 0 || curr.x >= size.x || \
		curr.y < 0 || curr.y >= size.y || \
		r->copy_m[curr.y][curr.x] == '1' || r->copy_m[curr.y][curr.x] == '.')
		return ;
	r->copy_m[curr.y][curr.x] = '.';
	flood_fill(r, size, (t_point){curr.x - 1, curr.y});
	flood_fill(r, size, (t_point){curr.x + 1, curr.y});
	flood_fill(r, size, (t_point){curr.x, curr.y - 1});
	flood_fill(r, size, (t_point){curr.x, curr.y + 1});
} */