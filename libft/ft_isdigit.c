/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:42:10 by amhan             #+#    #+#             */
/*   Updated: 2025/05/14 18:52:55 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c > 47) && (c < 58))
		return (2048);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	char c = '5';
	printf("my function : %d\n", ft_isdigit(c));
	printf("original : %d\n", isdigit(c));
	return (0);
}
*/
