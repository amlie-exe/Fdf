/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:53:38 by amhan             #+#    #+#             */
/*   Updated: 2025/05/06 19:43:24 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int find)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)find)
			return ((char *)&str[i]);
		i++;
	}
	if ((unsigned char)find == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	s1[] = "Hello world";
	char		*to_find1;
	char		*to_find2;

	to_find1 = ft_strchr(s1, 'l');
	to_find2 = strchr(s1, 'l');
	if (to_find1)
		printf("my function : %s\n", to_find1);
	else
		printf("my function : not found\n");
	if (to_find2)
		printf("original : %s\n", to_find2);
	else
		printf("original : not found\n");
	return (0);
}
*/
