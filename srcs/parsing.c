/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:29:32 by amhan             #+#    #+#             */
/*   Updated: 2025/08/01 18:02:45 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_lines_y(char *filename);
int		count_width_x(char *filename);
void	free_tab(char **tab);

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
}

int	count_lines_y(char *filename)
{
	int		map;
	int		count;
	char	*line;

	count = 0;
	map = open(filename, O_RDONLY);
	if (map < 0)
		return (-1);
	while (line = get_next_line(map))
	{
		count++;
		free(line);
	}
	close(map);
	return (count);
}

int	count_width_x(char *filename)
{
	int		map;
	int		i;
	char	*line;
	char	**column;

	map = open(filename, O_RDONLY);
	if (map < 0)
		return (-1);
	i = 0;
	line = get_next_line(map);
	if (!line)
		return (-1);
	column = ft_split(line, ' ');
	while (column[i])
		i++;
	free(line);
	free_tab(column);
	close(map);
	return (i);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}