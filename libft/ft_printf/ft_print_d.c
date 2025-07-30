/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:55:26 by amhan             #+#    #+#             */
/*   Updated: 2025/06/01 15:39:59 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_d(int nb, int *count_chars)
{
	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		(*count_chars) += 11;
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		(*count_chars) += 1;
	}
	if (nb >= 10)
	{
		ft_print_d((nb / 10), count_chars);
	}
	ft_putchar_fd(((nb % 10) + '0'), 1);
	(*count_chars)++;
}
