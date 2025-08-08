/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:28:13 by amhan             #+#    #+#             */
/*   Updated: 2025/08/08 17:50:45 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_bounds(t_map *map, t_view *view, t_bounds *bounds);
void	init_bounds(t_map *map, t_view *view, t_bounds *bounds);
void	update_bounds(t_point projected, t_bounds *bounds);

t_view	setup_view(t_map *map)
{
	t_view		view;
	t_bounds	bounds;
	float		map_width;
	float		map_height;

	view.angle = 0.523599;
	view.zoom = 1;
	view.offset_x = 0;
	view.offset_y = 0;
	calculate_bounds(map, &view, &bounds);
	map_width = bounds.max_x - bounds.min_x;
	map_height = bounds.max_y - bounds.min_y;
	view.zoom = fmin((WINDOW_WIDTH * 0.8) / map_width, (WINDOW_HEIGHT * 0.8)
			/ map_height);
	if (view.zoom < 1)
		view.zoom = 1;
	calculate_bounds(map, &view, &bounds);
	map_width = bounds.max_x - bounds.min_x;
	map_height = bounds.max_y - bounds.min_y;
	view.offset_x = (WINDOW_WIDTH - map_width) / 2 - bounds.min_x;
	view.offset_y = (WINDOW_HEIGHT - map_height) / 2 - bounds.min_y;
	return (view);
}

void	calculate_bounds(t_map *map, t_view *view, t_bounds *bounds)
{
	int		x;
	int		y;
	t_point	projected;

	init_bounds(map, view, bounds);
	y = 0;
	while (y < map->height_y)
	{
		x = 0;
		while (x < map->width_x)
		{
			projected = project_iso(x, y, map->data_z[y][x], view);
			update_bounds(projected, bounds);
			x++;
		}
		y++;
	}
}

void	init_bounds(t_map *map, t_view *view, t_bounds *bounds)
{
	t_point	projected;

	projected = project_iso(0, 0, map->data_z[0][0], view);
	bounds->min_x = projected.x;
	bounds->max_x = projected.x;
	bounds->min_y = projected.y;
	bounds->max_y = projected.y;
}

void	update_bounds(t_point projected, t_bounds *bounds)
{
	if (projected.x < bounds->min_x)
		bounds->min_x = projected.x;
	if (projected.x > bounds->max_x)
		bounds->max_x = projected.x;
	if (projected.y < bounds->min_y)
		bounds->min_y = projected.y;
	if (projected.y > bounds->max_y)
		bounds->max_y = projected.y;
}
