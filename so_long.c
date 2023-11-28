/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:34:57 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/28 20:47:16 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
//#include "libft.h"
#include "get_next_line.h"

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

void ft_parse (int argc, char **argv)
{
	int fd;
	//char *ret;
	//char *line;
	
	if (argc != 2)
		ft_error();
	if (ft_check_file (argv[1]) == 1)
		ft_error();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	/* while (get_next_line(fd))
	{
		line = get_next_line(fd);
		printf ("%s", line);
	}
	ret = ft_strjoin_free(get_next_line(fd), ' ');
	printf ("%s", ret); */
}


int main(int argc, char **argv)
{
	ft_parse(argc, argv);
	
	return (0);
}