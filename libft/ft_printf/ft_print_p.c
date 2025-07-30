/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:57:08 by amhan             #+#    #+#             */
/*   Updated: 2025/05/29 17:06:58 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	digit_to_hex(int digit);
static void	print_hex(unsigned long long hex_value, int *count_chars);

void	ft_print_p(void *address, int *count_chars)
{
	unsigned long long	hex_value;

	if (!address)
	{
		ft_print_s("(nil)", count_chars);
		return ;
	}
	ft_print_s("0x", count_chars);
	hex_value = (unsigned long long)address;
	print_hex(hex_value, count_chars);
}

static char	digit_to_hex(int digit)
{
	if ((digit >= 0) && (digit <= 9))
		return (digit + '0');
	else
		return ((digit - 10) + 'a');
}

static void	print_hex(unsigned long long hex_value, int *count_chars)
{
	if (hex_value >= 16)
		print_hex((hex_value / 16), count_chars);
	ft_print_c(digit_to_hex(hex_value % 16), count_chars);
}
