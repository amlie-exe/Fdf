/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:37:30 by amhan             #+#    #+#             */
/*   Updated: 2025/08/02 18:40:39 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map);

int	main(int ac, char **av)
{
	t_map	*map;
	int		x;
	int		y;

	if (ac == 2)
	{
		map = parse_map(av[1]);
		if (!map)
			return (1);
		ft_printf("width_x  : %d\n", map->width_x);
		ft_printf("height_y : %d\n", map->height_y);
		y = 0;
		while (y < map->height_y)
		{
			x = 0;
			while (x < map->width_x)
			{
				ft_printf("%d ", map->data_z[y][x]);
				x++;
			}
			ft_printf("\n");
			y++;
		}
	}
	return (0);
}

void	free_map(t_map *map)
{
	int y;

	if (!map)
		return ;
	y = 0;
	while (y < map->height_y)
	{
		free(map->data_z[y]);
		y++;
	}
	free(map->data_z);
	free(map);
}