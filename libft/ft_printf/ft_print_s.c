/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:48:06 by amhan             #+#    #+#             */
/*   Updated: 2025/05/29 17:07:03 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s(char *s, int *count_chars)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		(*count_chars) += 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		(*count_chars) += ft_strlen(s);
	}
}
