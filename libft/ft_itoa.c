/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:45:42 by amhan             #+#    #+#             */
/*   Updated: 2025/05/14 18:59:37 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(int n);

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = n_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	i = len - 1;
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static size_t	n_len(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	if (n == INT_MIN)
		return (11);
	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
/*
int	main(void)
{
	printf("result : %s\n", ft_itoa(-1000000));
	return (0);
}
*/
