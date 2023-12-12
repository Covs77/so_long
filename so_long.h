/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:01:04 by cleguina          #+#    #+#             */
/*   Updated: 2023/12/12 19:44:52 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define P 50
# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

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
}			t_point;

typedef struct s_texture
{
	mlx_texture_t	*ply;
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*co;
	mlx_texture_t	*ex;
}								t_texture;

typedef struct s_image
{
	mlx_image_t	*ply;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*co;
	mlx_image_t	*ex;
}							t_image;

typedef struct s_board
{
	char		**map;
	mlx_t		*mlx;
	t_point		dim;
	t_texture	tex;
	t_image		im;
	int			collect;
}				t_board;



/* leaks.c */
int		main(int argc, char **argv);
void	ft_error(int error);
char	**ft_parse(int argc, char **argv);
char	*ft_read_map_str(int fd);
void	ft_check_char_map(char *str);
void	ft_check_map(char *str);
int		ft_check_file_name(char *str);
void	ft_print_map(char **str);
char	**ft_map_matrix(char *str);
void	ft_check_map_matrix(char **map);
int		ft_matrix_lines(char **map);
int		ft_all_one(char *line);
void	ft_check_border(char **map);
void	ft_check_lines_map(char **map);
int		ft_only_one(char *str);
int		ft_first_last_row(char *line);
void	ft_check_collectibles(char *str);
void	ft_game (t_board *board);
void	init_board(t_board *board);
void	ft_map_size(t_board *board);
void	ft_playable_map(char **map);
void	ft_find_map(char **map, char c, t_point *pos);
//void	ft_print_pos(t_point pos_player);
void	ft_init_pos(t_point **pos);
char	**ft_copy_map(char **map);
void	flood_fill(char **map, t_point size, t_point pos);
void	ft_way_out(char **map, t_point pos);
void	ft_collect_all(char **map_copy, char **map);
void	ft_load_tex(t_board *board);
void	ft_txt_to_img(t_board *board);

#endif