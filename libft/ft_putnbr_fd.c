/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:00:09 by amhan             #+#    #+#             */
/*   Updated: 2025/05/08 12:28:28 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd ((n / 10), fd);
	}
	ft_putchar_fd (((n % 10) + '0'), fd);
}
/*
int	main(void)
{
	ft_putnbr_fd(-5, 2);
	ft_putchar_fd('\n', 1);
	return (0);
}
	*/