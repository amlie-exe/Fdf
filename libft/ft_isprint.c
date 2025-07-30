/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:41:55 by amhan             #+#    #+#             */
/*   Updated: 2025/05/14 18:53:09 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c < 32) || (c > 126))
		return (0);
	else
		return (16384);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char c = 30;
	printf("my function : %d\n", ft_isprint(c));
	printf("original : %d\n", isprint(c));
	return (0);
}
*/
