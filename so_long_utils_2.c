/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:44:47 by cova              #+#    #+#             */
/*   Updated: 2023/12/09 15:29:44 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void ft_print_pos(t_point pos)
{
    printf("pos[X]: %d\n", pos.x);
    printf("pos[Y]: %d\n", pos.y);
} */

void	ft_init_pos(t_point **pos)
{
	*pos = NULL;
	*pos = malloc(sizeof(t_point));
	if (*pos == NULL)
	{
		free(*pos);
		ft_error(6);
	}
	(*pos)->x = 0;
	(*pos)->y = 0;
}

void	ft_find_map(char **map, char c, t_point *pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
			{
				pos->y = i;
				pos->x = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
