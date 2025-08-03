/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:29:32 by amhan             #+#    #+#             */
/*   Updated: 2025/08/03 17:33:51 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_data(t_map *map, char *filename);
void	fill_data_line(t_map *map, int y, char *line);
int		count_lines_y(char *filename);
int		count_width_x(char *filename);

t_map	*parse_map(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width_x = count_width_x(filename);
	map->height_y = count_lines_y(filename);
	if (map->width_x <= 0 || map->height_y <= 0)
	{
		free(map);
		return (NULL);
	}
	map->data_z = malloc(sizeof(int *) * map->height_y);
	if (!map->data_z)
	{
		free(map);
		return (NULL);
	}
	fill_data(map, filename);
	return (map);
}

void	fill_data(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	y = 0;
	while (y < map->height_y)
	{
		line = get_next_line(fd);
		fill_data_line(map, y, line);
		free(line);
		y++;
	}
	close(fd);
}

void	fill_data_line(t_map *map, int y, char *line)
{
	char	**column;
	int		x;

	column = ft_split(line, ' ');
	map->data_z[y] = malloc(sizeof(int) * map->width_x);
	if (!map->data_z[y])
		return ;
	x = 0;
	while ((x < map->width_x) && column[x])
	{
		map->data_z[y][x] = ft_atoi(column[x]);
		x++;
	}
	free_tab(column);
}

int	count_lines_y(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

int	count_width_x(char *filename)
{
	int		fd;
	int		i;
	char	*line;
	char	**column;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (-1);
	}
	column = ft_split(line, ' ');
	while (column[i])
		i++;
	free(line);
	free_tab(column);
	close(fd);
	return (i);
}
