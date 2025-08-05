/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:37:30 by amhan             #+#    #+#             */
/*   Updated: 2025/08/05 17:45:47 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_map	*map;

	if (ac == 2)
	{
		map = parse_map(av[1]);
		if (!map)
			return (1);
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 1920, 1080, "Fdf");
		img.img = mlx_new_image(mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		draw_map_grid(map, &img);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}
	return (0);
}

/*
void	free_map(t_map *map)
{
	int	y;

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
	*/