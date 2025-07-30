/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:22:13 by amhan             #+#    #+#             */
/*   Updated: 2025/05/10 15:49:26 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = 0;
	srclen = ft_strlen(src);
	while ((dstlen < size) && dst[dstlen])
		dstlen++;
	if (dstlen >= size)
		return (size + srclen);
	i = 0;
	while (src[i] && ((dstlen + i) < (size - 1)))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	buf[10] = "hello";
	size_t	r;

	r = ft_strlcat(buf, " world", sizeof(buf));
	printf("resultat : %s\n", buf);
	printf("retour : %zu\n", r);
	return (0);
}
*/
