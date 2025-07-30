/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:12:08 by amhan             #+#    #+#             */
/*   Updated: 2025/05/21 18:59:49 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t len)
{
	size_t	i;
	char	*replace;

	i = 0;
	replace = src;
	while (i < len)
	{
		replace[i] = c;
		i++;
	}
	return (replace);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "hello world";

	printf("my function : %s\n", (char *)ft_memset(str, 'X', 5));
	printf("original : %s\n", (char *)memset(str, 'X', 5));
}
*/
