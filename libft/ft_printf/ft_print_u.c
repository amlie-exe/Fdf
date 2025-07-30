/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:36:49 by amhan             #+#    #+#             */
/*   Updated: 2025/05/29 17:07:08 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u(unsigned int nb, int *count_chars)
{
	if (nb >= 10)
	{
		ft_print_u((nb / 10), count_chars);
	}
	ft_putchar_fd(((nb % 10) + '0'), 1);
	(*count_chars)++;
}
