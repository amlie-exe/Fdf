/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:29:32 by amhan             #+#    #+#             */
/*   Updated: 2025/08/05 18:36:31 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_line_data(char *line);
t_list	*read_file_to_list(char *filename);
int		get_width_from_line(char *line);
void	fill_data_from_list(t_map *map, t_list *file_content);

t_map	*parse_map(char *filename)
{
	t_list	*file_content;
	t_map	*map;

	file_content = read_file_to_list(filename);
	if (!file_content)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height_y = ft_lstsize(file_content);
	map->width_x = get_width_from_line((char *)file_content->content);
	map->data_z = malloc(sizeof(int *) * map->height_y);
	fill_data_from_list(map, file_content);
	return (map);
}

int	is_line_data(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

t_list	*read_file_to_list(char *filename)
{
	t_list	*head;
	t_list	*new_node;
	char	*line;
	int		fd;

	head = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		new_node = ft_lstnew(line);
		if (!new_node)
		{
			free(line);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
	}
	close(fd);
	return (head);
}

int	get_width_from_line(char *line)
{
	int		width;
	char	**split_line;

	if (!line)
		return (0);
	split_line = ft_split(line, ' ');
	if (!split_line)
		return (0);
	width = 0;
	while (split_line[width])
		width++;
	free_tab(split_line);
	return (width);
}

void	fill_data_from_list(t_map *map, t_list *file_content)
{
	int		y;
	int		x;
	char	**split_line;

	y = 0;
	while (file_content)
	{
		split_line = ft_split((char *)file_content->content, ' ');
		map->data_z[y] = malloc(sizeof(int) * map->width_x);
		if (!map->data_z[y] || !split_line)
			return ;
		x = 0;
		while (x < map->width_x)
		{
			if (split_line[x])
				map->data_z[y][x] = ft_atoi(split_line[x]);
			else
				map->data_z[y][x] = 0;
			x++;
		}
		free_tab(split_line);
		file_content = file_content->next;
		y++;
	}
}
