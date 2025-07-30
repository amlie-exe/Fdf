/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexupper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:50:27 by amhan             #+#    #+#             */
/*   Updated: 2025/05/29 17:06:52 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	digit_to_hex(int digit);
static void	print_hex(unsigned int hex_value, int *count_chars);

void	ft_print_hexupper(unsigned int nb, int *count_chars)
{
	print_hex(nb, count_chars);
}

static char	digit_to_hex(int digit)
{
	if ((digit >= 0) && (digit <= 9))
		return (digit + '0');
	else
		return ((digit - 10) + 'A');
}

static void	print_hex(unsigned int hex_value, int *count_chars)
{
	if (hex_value >= 16)
		print_hex((hex_value / 16), count_chars);
	ft_print_c(digit_to_hex(hex_value % 16), count_chars);
}
