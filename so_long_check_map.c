/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:32:32 by cova              #+#    #+#             */
/*   Updated: 2023/12/14 19:53:07 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// chequeo el numero de lineas y columnas del mapa (minimo 3x5)

void	ft_check_lines_map(char **map)
{
	int	nmb_lines;
	int	i;

	i = 0;
	nmb_lines = ft_matrix_lines(map);
	if (nmb_lines < 3)
	{
		ft_free_matrix(map);
		ft_error(5);
	}
	while (i < nmb_lines)
	{
		if (ft_strlen(map[i]) < 5)
		{
			ft_free_matrix(map);
			ft_error(5);
		}
		else if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			ft_free_matrix(map);
			ft_error(5);
		}
		i++;
	}
}
// Chequea que los bordes del mapa sean 1

void	ft_check_border(char **map)
{
	int		i;
	int		nmb_lines;
	char	*line;

	i = 0;
	nmb_lines = ft_matrix_lines(map);
	line = map[i];
	while (line != NULL)
	{
		if (i == 0 || i == nmb_lines - 1)
		{
			if (ft_all_one(map[i]) == 1)
			{
				ft_free_matrix(map);
				ft_error(5);
			}
		}
		else if (ft_first_last_row(line) == 1)
		{
			ft_free_matrix(map);
			ft_error(5);
		}
		i++;
		line = map[i];
	}
}

//Busca que al menos haya un coleccionable

void	ft_check_collectibles(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'C')
			return ;
		else
			i++;
	}
	ft_error(8);
}
