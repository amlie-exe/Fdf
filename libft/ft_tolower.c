/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:13:16 by amhan             #+#    #+#             */
/*   Updated: 2025/05/14 18:54:10 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c > 64) && (c < 91))
		c += 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char c = 'A';
	printf("my function : %c\n", ft_tolower(c));
	printf("original : %c\n", tolower(c));
	return (0);
}
*/
