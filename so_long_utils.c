/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:22:29 by cova              #+#    #+#             */
/*   Updated: 2023/12/09 15:09:15 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(char **str)
{
	int	i;

	i = 0;
	if (*str != NULL)
	{
		printf("Mapa (matriz)\n");
		while (str[i] != NULL)
		{
			printf("%s\n", str[i]);
			i++;
		}
	}
}

int	ft_matrix_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}
// devuelve 1 si hay algun caracter que no sea 1 en la linea
// 0 si esta ok.

int	ft_all_one(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

// Devuelve 1 si hay mas de un Player o Exit en el mapa 

int	ft_only_one(char *str)
{
	int	p;
	int	e;
	int	i;

	p = 0;
	e = 0;
	i = 0;
	while (str[i] != '\0' && (p < 2 && e < 2))
	{
		if (str[i] == 'P')
			p++;
		if (str[i] == 'E')
			e++;
		i++;
	}
	if (p == 1 && e == 1)
		return (0);
	return (1);
}

// devuelve 1 si la calumna no empieza y acaba en 1
int	ft_first_last_row(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[0] != '1' || line[len - 1] != '1')
		return (1);
	return (0);
}
