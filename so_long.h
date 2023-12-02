/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:01:04 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/02 14:54:10 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


//# include "../MLX42/include/MLX42/MLX42.h"

/* Define window size */
/* # define WIDTH 50
# define HEIGHT 50 */

/* Color definitions */

# define BOLD     "\033[1m"
# define BLACK    "\033[30;1m"
# define RED      "\033[31;1m"
# define GREEN    "\033[32;1m"
# define YELLOW   "\033[33;1m"
# define BLUE     "\033[34;1m"
# define MAGENTA  "\033[35;1m"
# define CYAN     "\033[36;1m"
# define WHITE    "\033[37;1m"
# define RESET    "\033[0m" 



typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

/* leaks.c */
int		main(int argc, char **argv);
void	ft_error(int error);
char 	**ft_parse(int argc, char **argv);
char 	*ft_read_map_str(int fd);
void 	ft_check_char_map(char *str);
void 	ft_check_map(char *str);
int		ft_check_file_name(char *str);
void 	ft_print_map(char **str);
char	**ft_map_matrix(char *str);
void 	ft_check_map_matrix(char **map);
int 	ft_matrix_lines(char **map);
int 	ft_all_one(char *line);
void	ft_check_border(char **map);
void	ft_check_lines_map(char **map);
int		ft_only_one(char *str);
int 	ft_first_last_row(char *line);


#endif