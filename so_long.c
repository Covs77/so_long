/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:34:57 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/01 20:05:04 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "Libft/libft.h"


void ft_error (int error)
{
	
	if (error == 1) 
		write (2, "Error\nWrong number of arguments\n", 33);
	if (error == 2)
		write (2, "Error\nWrong file name\n", 23);
	if (error == 3)
		write (2, "Error\nWrong file descriptor\n", 29);
	if (error == 4)
		write (2, "Error\nEmpty file\n", 18);
	if (error == 5)
		write (2, "Error\nWrong map\n", 17);
	if (error == 6)
		write (2, "Error\nMalloc error\n", 20);	
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
		ft_error(6);
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
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' && str[i] != 'E' && str[i] != 'P' && str[i] != '\n')
		{	free(str);
			ft_error(5);
		}
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
		ft_error(1);
	if (ft_check_file (argv[1]) == 1)
		ft_error(5);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error(3);
	}
	str = NULL;
	str = ft_read_map(fd);
	ft_check_map(str);
	printf("%s\n", str);
}

void ft_l(void)
{
	system("leaks so_long");

} 
int main(int argc, char **argv)
{
	ft_l();
	ft_parse(argc, argv);
	
	return (0);
}