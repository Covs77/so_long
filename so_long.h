/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:01:04 by cleguina          #+#    #+#             */
/*   Updated: 2023/11/29 20:31:11 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "Libft/libft.h"
# include <stdio.h>
//# include "../MLX42/include/MLX42/MLX42.h"

/* Define window size */
/* # define WIDTH 50
# define HEIGHT 50

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
void	ft_error (void);
void	ft_parse (int argc, char *argv);
char	*ft_read_map(int fd);



#endif