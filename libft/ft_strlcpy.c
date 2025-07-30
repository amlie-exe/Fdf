/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:19:57 by amhan             #+#    #+#             */
/*   Updated: 2025/05/04 18:03:55 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	if (!destsize)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < (destsize - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
int	main(void)
{
	char	s1[] = "hello";
	char	s2[] = "world";

	printf("my function : %zu\n", ft_strlcpy(s1, s2, 3));
	return (0);
}
*/
