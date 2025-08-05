/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:42:29 by amhan             #+#    #+#             */
/*   Updated: 2025/08/05 19:51:37 by amhan            ###   ########.fr       */
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

# define WINDOW_WIDTH 1366
# define WINDOW_HEIGHT 768

typedef struct s_map
{
	int		width_x;
	int		height_y;
	int		**data_z;
}			t_map;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}			t_point;

typedef struct s_view
{
	int		zoom;
	int		offset_x;
	int		offset_y;
	float	angle;
	float	z_scale;
}			t_view;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

t_map		*parse_map(char *filename);
void		free_tab(char **tab);
t_point		project_iso(int x, int y, int z, t_view *view);
void		draw_lines(t_point a, t_point b, t_data *img, t_view *view);
void		draw_map_row(t_map *map, t_data *img, int y, t_view *view);
void		draw_map_grid(t_map *map, t_data *img);
int			is_line_data(char *line);
t_list		*read_file_to_list(char *filename);
int			get_width_from_line(char *line);
void		fill_data_from_list(t_map *map, t_list *file_content);
int			get_z_range(t_map *map);

#endif