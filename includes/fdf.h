/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:42:29 by amhan             #+#    #+#             */
/*   Updated: 2025/08/01 15:53:03 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct s_map
{
	int	width_x;
	int	height_y;
	int	**data_z;
}		t_map;

t_map	*parse_map(char *filename);
int		count_lines_y(char *filename);
int		count_width_x(char *filename);
void	free_tab(char **tab);

#endif