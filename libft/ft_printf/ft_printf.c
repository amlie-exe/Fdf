/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:09:48 by amhan             #+#    #+#             */
/*   Updated: 2025/06/01 13:42:55 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_format(char c, va_list args, int *count_chars);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count_chars;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count_chars = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			else
				check_format(format[i], args, &count_chars);
		}
		else
			ft_print_c(format[i], &count_chars);
		i++;
	}
	va_end(args);
	return (count_chars);
}

static void	check_format(char format, va_list args, int *count_chars)
{
	if (format == 's')
		ft_print_s(va_arg(args, char *), count_chars);
	else if (format == 'c')
		ft_print_c((char)va_arg(args, int), count_chars);
	else if (format == '%')
		ft_print_c('%', count_chars);
	else if (format == 'd' || format == 'i')
		ft_print_d(va_arg(args, int), count_chars);
	else if (format == 'u')
		ft_print_u(va_arg(args, unsigned int), count_chars);
	else if (format == 'p')
		ft_print_p(va_arg(args, void *), count_chars);
	else if (format == 'x')
		ft_print_hexlower(va_arg(args, unsigned int), count_chars);
	else if (format == 'X')
		ft_print_hexupper(va_arg(args, unsigned int), count_chars);
}
