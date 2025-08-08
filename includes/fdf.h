/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:42:29 by amhan             #+#    #+#             */
/*   Updated: 2025/08/08 18:54:44 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define KEY_ESC 0xff1b
# define ON_DESTROY 17

typedef struct s_map
{
	int		width_x;
	int		height_y;
	int		**data_z;
}			t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_view
{
	int		zoom;
	int		offset_x;
	int		offset_y;
	float	angle;
}			t_view;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	*map;
	t_view	view;
}			t_fdf;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}			t_point;

typedef struct s_bounds
{
	float	min_x;
	float	max_x;
	float	min_y;
	float	max_y;
}			t_bounds;

typedef struct s_line
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	int		steps;
}			t_line;

void		draw_lines(t_point a, t_point b, t_data *img, t_view *view);
void		plot_line(t_line *line, t_data *img, t_view *view);
void		draw_map_grid(t_map *map, t_data *img);
t_view		setup_view(t_map *map);
void		draw_map_row(t_map *map, t_data *img, int y, t_view *view);
int			close_program(t_fdf *fdf);
int			expose_hook(t_fdf *fdf);
int			key_hook(int keycode, t_fdf *fdf);
t_map		*parse_map(char *filename);
t_list		*read_file_to_list(char *filename);
int			get_width_from_line(char *line);
void		fill_data_from_list(t_map *map, t_list *file_content);
void		free_map(t_map *map);
t_point		project_iso(int x, int y, int z, t_view *view);
void		my_pixel_put(t_data *data, int x, int y, unsigned int color);
void		calculate_bounds(t_map *map, t_view *view, t_bounds *bounds);
void		init_bounds(t_map *map, t_view *view, t_bounds *bounds);
void		update_bounds(t_point projected, t_bounds *bounds);

#endif