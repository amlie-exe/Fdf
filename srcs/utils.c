/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:20:57 by amhan             #+#    #+#             */
/*   Updated: 2025/08/05 20:05:01 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_z_range(t_map *map)
{
	int z_min;
	int z_max;
	int x;
	int y;

	z_min = map->data_z[0][0];
	z_max = map->data_z[0][0];
	y = 0;
	while (y < map->height_y)
	{
		x = 0;
		while (x < map->width_x)
		{
			if (map->data_z[y][x] < z_min)
				z_min = map->data_z[y][x];
			if (map->data_z[y][x] > z_max)
				z_max = map->data_z[y][x];
			x++;
		}
		y++;
	}
	return (z_max - z_min);
}