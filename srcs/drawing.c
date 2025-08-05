/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:48:52 by amhan             #+#    #+#             */
/*   Updated: 2025/08/05 22:11:11 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_lines(t_point a, t_point b, t_data *img, t_view *view);
void	draw_map_row(t_map *map, t_data *img, int y, t_view *view);
void	my_pixel_put(t_data *data, int x, int y, unsigned int color);
void	calculate_bounds(t_map *map, t_view *view, t_bounds *bounds);

t_point	project_iso(int x, int y, int z, t_view *view)
{
	t_point	p;

	p.x = ((x - y) * cos(view->angle)) * view->zoom;
	p.y = ((x + y) * sin(view->angle) - z) * view->zoom;
	return (p);
}

void	draw_lines(t_point a, t_point b, t_data *img, t_view *view)
{
	int		i;
	float	dx;
	float	dy;
	float	steps;
	float	x;
	float	y;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	if (steps == 0)
	{
		my_pixel_put(img, a.x + view->offset_x, a.y + view->offset_y,
			0x00FFFFFF);
		return ;
	}
	dx = dx / steps;
	dy = dy / steps;
	x = a.x;
	y = a.y;
	i = 0;
	while (i <= steps)
	{
		my_pixel_put(img, x + view->offset_x, y + view->offset_y, 0x00FFFFFF);
		x += dx;
		y += dy;
		i++;
	}
}

void	draw_map_grid(t_map *map, t_data *img)
{
	int			y;
	t_view		view;
	t_bounds	bounds;

	float map_width, map_height;
	float scale_x, scale_y;
	view.angle = 0.523599;
	view.zoom = 1;
	view.offset_x = 0;
	view.offset_y = 0;
	calculate_bounds(map, &view, &bounds);
	map_width = bounds.max_x - bounds.min_x;
	map_height = bounds.max_y - bounds.min_y;
	scale_x = (WINDOW_WIDTH * 0.8) / map_width;
	scale_y = (WINDOW_HEIGHT * 0.8) / map_height;
	if (scale_x < scale_y)
		view.zoom = scale_x;
	else
		view.zoom = scale_y;
	if (view.zoom < 1)
		view.zoom = 1;
	calculate_bounds(map, &view, &bounds);
	map_width = bounds.max_x - bounds.min_x;
	map_height = bounds.max_y - bounds.min_y;
	view.offset_x = (WINDOW_WIDTH - map_width) / 2 - bounds.min_x;
	view.offset_y = (WINDOW_HEIGHT - map_height) / 2 - bounds.min_y;
	y = 0;
	while (y < map->height_y)
	{
		draw_map_row(map, img, y, &view);
		y++;
	}
}

void	draw_map_row(t_map *map, t_data *img, int y, t_view *view)
{
	int		x;
	t_point	current;
	t_point	next_x;
	t_point	next_y;

	if (!map->data_z[y])
		return ;
	x = 0;
	while (x < map->width_x)
	{
		current = project_iso(x, y, map->data_z[y][x], view);
		if ((x + 1) < map->width_x)
		{
			next_x = project_iso(x + 1, y, map->data_z[y][x + 1], view);
			draw_lines(current, next_x, img, view);
		}
		if ((y + 1) < map->height_y)
		{
			next_y = project_iso(x, y + 1, map->data_z[y + 1][x], view);
			draw_lines(current, next_y, img, view);
		}
		x++;
	}
}

void	my_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	calculate_bounds(t_map *map, t_view *view, t_bounds *bounds)
{
	t_point	projected;

	int x, y;
	projected = project_iso(0, 0, map->data_z[0][0], view);
	bounds->min_x = projected.x;
	bounds->max_x = projected.x;
	bounds->min_y = projected.y;
	bounds->max_y = projected.y;
	y = 0;
	while (y < map->height_y)
	{
		x = 0;
		while (x < map->width_x)
		{
			projected = project_iso(x, y, map->data_z[y][x], view);
			if (projected.x < bounds->min_x)
				bounds->min_x = projected.x;
			if (projected.x > bounds->max_x)
				bounds->max_x = projected.x;
			if (projected.y < bounds->min_y)
				bounds->min_y = projected.y;
			if (projected.y > bounds->max_y)
				bounds->max_y = projected.y;
			x++;
		}
		y++;
	}
}
