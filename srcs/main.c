/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:37:30 by amhan             #+#    #+#             */
/*   Updated: 2025/08/03 17:51:58 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_data *data, int x, int y, unsigned int color);

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	(void)av;
	if (ac == 2)
	{
		mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 1920, 1080, "Fdf");
		img.img = mlx_new_image(mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		my_pixel_put(&img, 960, 540, 0x00FF0000);
		my_pixel_put(&img, 961, 540, 0x00FF0000);
		my_pixel_put(&img, 959, 540, 0x00FF0000);
		my_pixel_put(&img, 960, 541, 0x00FF0000);
		my_pixel_put(&img, 960, 539, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	}
	return (0);
}

void	my_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// ^ adresse de dst : determine la position (les coordonnes (x, y))
	*(unsigned int *)dst = color;
	// ^ valeur a l'adresse dst : on veut la couleur qui se trouve a la bonne coordonnee
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