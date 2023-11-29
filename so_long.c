/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:34:57 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/29 21:02:22 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "Libft/libft.h"


void ft_error (void)
{
	write (2, "Error\n", 6);
	exit(-1);
}

int	ft_check_file (char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b' || str[i - 4] != '.')
		return (1);
	return (0);
	
}



char *ft_read_map(int fd)
{
	char	*line;
	char	*str;
	
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		ft_error();
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

void ft_check_map(char *str)
{	
	int i;
	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'E' && str[i] != 'P')
			ft_error();
		else 
			i++;
	}


}

void ft_parse (int argc, char **argv)
{
	int fd;
	char *str;
	
	//int i;
	
	if (argc != 2)
		ft_error();
	if (ft_check_file (argv[1]) == 1)
		ft_error();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error();
	}
	str = NULL;
	str = ft_read_map(fd);
	ft_check_map(str);
}

/* void ft_l(void)
{
	system("leaks so_long");

} */
int main(int argc, char **argv)
{
	//ft_l();
	ft_parse(argc, argv);
	
	return (0);
}