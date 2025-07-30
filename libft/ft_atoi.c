/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:07:33 by amhan             #+#    #+#             */
/*   Updated: 2025/05/21 12:10:05 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == ' '))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ((str[i] >= '0') && (str[i] <= '9')))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "   +1234ab567";

	printf("my function : %d\n", ft_atoi(s));
	printf("original : %d\n", atoi(s));
	return (0);
}
*/
