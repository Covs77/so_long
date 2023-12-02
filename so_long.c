/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:34:57 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/02 14:35:58 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void ft_l(void)
{
	system("leaks so_long");

} 

void ft_error (int error)
{
	if (error == 1) 
		write (2, "Error\nWrong number of arguments\n", 33);
	if (error == 2)
		write (2, "Error\nWrong file name\n", 23);
	if (error == 3)
		write (2, "Error\nCan`t open file\n", 22);
	if (error == 4)
		write (2, "Error\nEmpty file\n", 18);
	if (error == 5)
		write (2, "Error\nWrong map(size)\n", 23);
	if (error == 6)
		write (2, "Error\nMalloc error\n", 20);	
	if (error == 7)
		write (2, "Error\nWrong map(more than 1 e or p)\n", 36);
	
	exit(-1);
}



int main(int argc, char **argv)
{
	char **map;
		
	ft_l();
	map = ft_parse(argc, argv);
	ft_print_map(map);
	return (0);
}