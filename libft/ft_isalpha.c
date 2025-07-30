/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 08:53:03 by amhan             #+#    #+#             */
/*   Updated: 2025/05/14 18:52:35 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (((c > 64) && (c < 91)) || ((c > 96) && (c < 123)))
		return (1024);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char c = '9';
	printf("my funtion : %d\n", ft_isalpha(c));
	printf("original : %d\n", isalpha(c));
	return (0);
}
*/
