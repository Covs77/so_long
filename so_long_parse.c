/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:13:16 by cova              #+#    #+#             */
/*   Updated: 2023/12/02 14:58:40 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file_name(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b' || str[i - 4] != '.')
		return (1);
	return (0);
}

void ft_check_char_map(char *str)
{
	int i;
    int error;
    char c;
	int len;
	
	i = 0;
    c = str[i];
	len = ft_strlen(str);
	error = 0;
	while((i <= len) && error == 0)
	{
		c = str[i];
		if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P' && c != '\n' && c != '\0')
			error = 1;
		else
        	i++;
    }	
	if (error == 0)
        error = ft_only_one(str);
    if (error == 1)	
    {
		free(str);
		ft_error(7);
    }
}

void ft_check_map(char *str)
{	
	
	ft_check_char_map(str);
	//printf("\nMapa chequeado, lineas y char\n");
	//voy por aqui

}

char **ft_parse(int argc, char **argv)
{
	int fd;
	char *str;
    char **map;

	if (argc != 2)
		ft_error(1);
	if (ft_check_file_name(argv[1]) == 1)
	{
		ft_error(5);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error(3);
	}
	str = NULL;
	str = ft_read_map_str(fd);
	ft_check_map(str);
	map = ft_map_matrix(str);
   	return(map);
}
