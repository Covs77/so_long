/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cova <cova@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:44:47 by cova              #+#    #+#             */
/*   Updated: 2023/12/07 19:21:49 by cova             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_print_pos(t_point pos)
{
    printf("pos[X]: %d\n", pos.x);
    printf("pos[Y]: %d\n", pos.y);
}

void ft_init_pos (t_point **pos)
{
    *pos = malloc(sizeof(t_point));
    if (*pos == NULL) 
		ft_error(6);
    (*pos)->x = 0;
    (*pos)->y = 0;
}