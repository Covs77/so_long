/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:44:47 by cova              #+#    #+#             */
/*   Updated: 2023/12/14 19:46:18 by cleguina         ###   ########.fr       */
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

void	ft_count_collect(t_board *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (b->map[i] != NULL)
	{
		while (b->map[i][j] != '\0')
		{
			if (b->map[i][j] == 'C')
				b->collect++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_print_moves(int moves)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(moves, 1);
	ft_putchar_fd('\n', 1);
}
