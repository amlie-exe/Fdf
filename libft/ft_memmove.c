/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:51:29 by amhan             #+#    #+#             */
/*   Updated: 2025/05/22 09:41:41 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (dest == src || len == 0)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (i < len)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[] = "blablabla";
	char	src[] = "newstring";

	printf("BEFORE : dest = %s / src = %s\n", dest, src);
	ft_memmove(dest, src, 4);
	printf("AFTER (my function) : dest = %s / src = %s\n", dest, src);
	memmove(dest, src, 4);
	printf("AFTER (original) : dest = %s / src = %s\n", dest, src);
	return (0);
}
	La fonction memmove() fait la même chose que la fonction memcpy(),
	MAIS ! la copie est faite de manière non destructive.
	Cela signifie que src et dst peuvent se chevaucher en mémoire.
	Cette fonction n'écrase pas une partie 
	ou la totalité de la chaîne lors de la copie.
*/
