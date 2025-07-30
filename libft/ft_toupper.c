/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:39:52 by amhan             #+#    #+#             */
/*   Updated: 2025/05/14 18:54:20 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c > 96) && (c < 123))
		c -= 32;
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'a';
	printf("my function : %c\n", ft_toupper(c));
	printf("original : %c\n", toupper(c));
	return (0);
}
*/
