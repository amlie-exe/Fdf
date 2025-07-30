/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:40:24 by amhan             #+#    #+#             */
/*   Updated: 2025/05/14 18:52:46 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	unsigned char c = 200;
	printf("%d\n", ft_isascii(c));
	printf("%d\n", isascii(c));
	return (0);
}
*/
