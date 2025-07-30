/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:30:47 by amhan             #+#    #+#             */
/*   Updated: 2025/05/04 18:38:23 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (len == 0)
		return (0);
	while ((str1[i] != '\0') && (str2[i] != '\0') && (str1[i] == str2[i])
		&& (i < (len - 1)))
	{
		i++;
	}
	return (str1[i] - str2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "hello World";
	char	s2[] = "hello world";

	printf("my function : %d\n", ft_strncmp(s1, s2, 9));
	printf("original : %d\n", strncmp(s1, s2, 9));
	return (0);
}
*/
