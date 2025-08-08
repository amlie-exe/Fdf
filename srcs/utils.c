/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:20:57 by amhan             #+#    #+#             */
/*   Updated: 2025/08/08 17:50:24 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	{
		while (y < map->height_y)
		{
			if (map->data_z[y])
				free(map->data_z[y]);
			y++;
		}
		free(map->data_z);
	}
	free(map);
}

t_point	project_iso(int x, int y, int z, t_view *view)
{
	t_point	p;

	p.x = ((x - y) * cos(view->angle)) * view->zoom;
	p.y = ((x + y) * sin(view->angle) - z) * view->zoom;
	return (p);
}

