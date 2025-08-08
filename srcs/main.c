/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:37:30 by amhan             #+#    #+#             */
/*   Updated: 2025/08/08 17:44:52 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_program(t_fdf *fdf);
int	expose_hook(t_fdf *fdf);
int	key_hook(int keycode, t_fdf *fdf);

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac == 2)
	{
		fdf.map = parse_map(av[1]);
		if (!fdf.map)
			return (1);
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, 1920, 1080, "Fdf");
		fdf.img.img = mlx_new_image(fdf.mlx, 1920, 1080);
		fdf.img.addr = mlx_get_data_addr(fdf.img.img, &fdf.img.bits_per_pixel,
				&fdf.img.line_length, &fdf.img.endian);
		draw_map_grid(fdf.map, &fdf.img);
		mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
		mlx_key_hook(fdf.win, key_hook, &fdf);
		mlx_hook(fdf.win, ON_DESTROY, 0, close_program, &fdf);
		mlx_hook(fdf.win, 12, 0, expose_hook, &fdf);
		mlx_loop(fdf.mlx);
	}
	return (0);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		close_program(fdf);
	return (0);
}

int	close_program(t_fdf *fdf)
{
	free_map(fdf->map);
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	exit(0);
	return (0);
}

int	expose_hook(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
	return (0);
}

