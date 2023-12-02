/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_read_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:20:06 by cova              #+#    #+#             */
/*   Updated: 2023/12/02 15:00:22 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *ft_read_map_str(int fd)
{
	char	*line;
	char	*str;
	
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		ft_error(4);
	}
	str = NULL;
	str = ft_strjoin_free(str, line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			str = ft_strjoin_free(str, line);
	}
	return (str);
}

void ft_check_map_matrix(char **map)
{
 
    ft_check_lines_map(map);
    ft_check_border(map);

    
}


char **ft_map_matrix(char *str)
{
    char **map;
    
    map = ft_split(str, '\n');
    ft_check_map_matrix(map);
    return (map);


}