/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:43:20 by amhan             #+#    #+#             */
/*   Updated: 2025/05/22 09:33:31 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int find, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < len)
	{
		if (str[i] == (unsigned char)find)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[] = "Beauty is terror";
	const char	ch = 't';
	char		*result01;
	char		*result02;

	result01 = (char *)ft_memchr(str, ch, strlen(str));
	result02 = (char *)memchr(str, ch, strlen(str));
	if (result01 != NULL)
	{
		printf("'%c' found at position %ld\n", ch, result01 - str);
	}
	else
	{
		printf("'%c' is not found in the string\n", ch);
	}
	if (result02 != NULL)
	{
		printf("'%c' found at position %ld\n", ch, result02 - str);
	}
	else
	{
		printf("'%c' is not found in the string\n", ch);
	}
}
	NB : La fonction memchr() fonctionne comme la fonction strchr().
	memchr() travaille avec des chaînes d'octets (void *),
	alors que strchr() travaille avec des chaînes de charactères (char *).
	memchr() a également un troisième paramètre, len.
	len ispécifie explicitement combien d'octets doivent être examinés. 
	Nous avons besoin de ce paramètre car s len'est pas une chaîne de caractères.
	Donc, s len'a pas de caractère de terminaison NUL.
	Sans len, memchr() ne saurait pas où s'arrêter.
	Nous lirions un nombre aléatoire d'octets à chaque fois.
	*/