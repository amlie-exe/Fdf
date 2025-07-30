/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 08:36:44 by amhan             #+#    #+#             */
/*   Updated: 2025/05/08 15:26:28 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "hello world!";

	printf("my function : %lu\n", ft_strlen(s1));
	printf("original : %lu\n", strlen(s1));
	return (0);
}
*/
