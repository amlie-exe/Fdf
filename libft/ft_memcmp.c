/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:53:41 by amhan             #+#    #+#             */
/*   Updated: 2025/05/05 13:38:03 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "Beauty is terror";
	char	str2[] = "Beauty is terror";
	int		result01;
	int		result02;

	result01 = ft_memcmp(str1, str2, 10);
	result02 = memcmp(str1, str2, 10);
	if (result01 < 0)
		printf("s1 < s2 : %d\n", result01);
	else if (result01 == 0)
		printf("s1 = s2 : %d\n", result01);
	else
		printf("s1 > s2 : %d\n", result01);
	if (result02 < 0)
		printf("s1 < s2 : %d\n", result02);
	else if (result02 == 0)
		printf("s1 = s2 : %d\n", result02);
	else
		printf("s1 > s2 : %d\n", result02);
}
		*/