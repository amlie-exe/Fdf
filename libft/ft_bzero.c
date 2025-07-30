/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:41:37 by amhan             #+#    #+#             */
/*   Updated: 2025/05/04 17:58:34 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *src, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = src;
	while (i < len)
	{
		dest[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "hello world";

	printf("BEFORE / my function : %s\n", str);
	printf("BEFORE / my function : %s\n", str);
	ft_bzero(str, 5);
	bzero(str, 5);
	printf("AFTER / my function : %s\n",str);
	printf("AFTER / original : %s\n", str);
	return (0);
}
*/
