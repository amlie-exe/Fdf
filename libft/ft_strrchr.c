/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:52:13 by amhan             #+#    #+#             */
/*   Updated: 2025/05/06 16:48:39 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int find)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)find)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char s1[] = "Beauty is terror";
	char *to_find1 = ft_strrchr(s1, 'g');
	char *to_find2 = strrchr(s1, 'g');

	if (to_find1)
		printf("my function : %s\n", to_find1);
	else
		printf("my function : %s\n", to_find1);

	if (to_find2)
		printf("original : %s\n", to_find2);
	else
		printf("original : %s\n", to_find2);
	return (0);	
}
*/
