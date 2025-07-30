/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:22:13 by amhan             #+#    #+#             */
/*   Updated: 2025/05/14 18:52:21 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c > 64) && (c < 91)) || ((c > 96) && (c < 123)))
		return (8);
	if ((c > 47) && (c < 58))
		return (8);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char c = '?';
	printf("my function : %d\n", ft_isalnum(c));
	printf("original : %d\n", isalnum(c));
	return (0);
}
*/
