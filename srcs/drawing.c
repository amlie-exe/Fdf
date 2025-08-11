/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:48:52 by amhan             #+#    #+#             */
/*   Updated: 2025/08/11 11:30:57 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map_row(t_map *map, t_data *img, int y, t_view *view);
void	draw_lines(t_point a, t_point b, t_data *img, t_view *view);
void	my_pixel_put(t_data *data, int x, int y, unsigned int color);
void	plot_line(t_line *line, t_data *img, t_view *view);

void	draw_map_grid(t_map *map, t_data *img)
{
	int		y;
	t_view	view;

	view = setup_view(map);
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

void	draw_lines(t_point a, t_point b, t_data *img, t_view *view)
{
	t_line	line;

	line.dx = b.x - a.x;
	line.dy = b.y - a.y;
	if (fabs(line.dx) > fabs(line.dy))
		line.steps = fabs(line.dx);
	else
		line.steps = fabs(line.dy);
	if (line.steps == 0)
	{
		my_pixel_put(img, a.x + view->offset_x, a.y + view->offset_y,
			0x00FFFFFF);
		return ;
	}
	line.dx /= line.steps;
	line.dy /= line.steps;
	line.x = a.x;
	line.y = a.y;
	plot_line(&line, img, view);
}

void	my_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	plot_line(t_line *line, t_data *img, t_view *view)
{
	int	i;

	i = 0;
	while (i <= line->steps)
	{
		my_pixel_put(img, line->x + view->offset_x, line->y + view->offset_y,
			0x00FFFFFF);
		line->x += line->dx;
		line->y += line->dy;
		i++;
	}
}
