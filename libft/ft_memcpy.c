/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:44:09 by amhan             #+#    #+#             */
/*   Updated: 2025/05/22 09:39:22 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "hello world";
	char	s2[] = "bye bye";

	printf("my function : %s\n", (char *)ft_memcpy(s2, s1, 4));
	printf("original : %s\n", (char *)memcpy(s2, s1, 4));
	return (0);
}
	NB : La fonction memcpy copie au maximum n octets de src à dst.
	Elle fonctionne comme la fonction strcpy,
	sauf que memcpy accepte void * comme paramètres.
	Il est donc possible de lui donner n'importe quel type de pointeur à copier.
	memcpy ne gère pas les chevauchements.
	Cela veut dire qu'on a un écrasement des données
	qui n'ont pas encore été lues en cas de chevauchement.
	On a un comportement indéfini avec src et dest.
	Il faut se référer à memmove pour la gestion des chevauchements.
*/