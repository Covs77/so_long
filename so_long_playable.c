/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_playable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:39:46 by cova              #+#    #+#             */
/*   Updated: 2023/12/06 14:10:18 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int *ft_find_map(char **map, char c)
{   
    int *position;
    int i;
    int j;
    
    i = 0;
    j = 0;
    position = NULL;
    position[0] = i;
    position[1] = j;
    printf("Aqui\n");
    while (map[i])
    {
        while (map[i][j] != '\0')
        {
            if (map[i][j] == c)
            {
                position[0] = i;
                position[1] = j;
                return (position);
            }
            printf ("columna j: %d\n", j);
            j++;
        }
        j = 0;
        printf ("fila i: %d\n", i);
        i++;
    }
    return (NULL);
}


void ft_playable_map(char **map)
{
    int *pos_player = NULL;
    //char *pos_exit;
    
    printf ("\nes jugable?\n");
    pos_player[0] = 0;
    pos_player[1] = 0;
      
      
    //segmentation fault
      ft_print_pos(pos_player);
    pos_player = ft_find_map(map, 'P');
  

    
}
