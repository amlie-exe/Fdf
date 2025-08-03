/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:48:52 by amhan             #+#    #+#             */
/*   Updated: 2025/08/03 17:33:39 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project_iso(int x, int y, int z)
{
	t_point	p;
	float	angle;

	angle = 0.523599;
	p.x = (x - y) * cos(angle);
	p.y = (x + y) * sin(angle) - z;
	return (p);
}

void	draw_lines(t_point a, t_point b, t_data *img)
{
	int		i;
	float	dx;
	float	dy;
	float	steps;
	float	x;
	float	y;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	dx = dx / steps;
	dy = dy / steps;
	x = a.x;
	y = a.y;
	i = 0;
	while (i <= steps)
	{
		my_pixel_put(img, x + 960, y + 540, 0x00FFFFFF);
		x += dx;
		y += dy;
		i++;
	}
}
