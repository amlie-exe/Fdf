/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:42:29 by amhan             #+#    #+#             */
/*   Updated: 2025/08/03 17:52:04 by amhan            ###   ########.fr       */
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

t_map		*parse_map(char *filename);
void		fill_data(t_map *map, char *filename);
void		fill_data_line(t_map *map, int y, char *line);
int			count_lines_y(char *filename);
int			count_width_x(char *filename);
void		free_tab(char **tab);

#endif