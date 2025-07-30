/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:00:24 by amhan             #+#    #+#             */
/*   Updated: 2025/06/07 13:01:29 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < ft_strlen(src))
	{
		dest[i] = src[i];
		i++;
	}
	dest[ft_strlen(src)] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "hello world";

	printf("original : %s\n", str);
	printf("copy : %s\n", ft_strdup(str));
	return (0);
}
*/
