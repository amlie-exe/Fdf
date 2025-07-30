/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:29:11 by amhan             #+#    #+#             */
/*   Updated: 2025/05/05 14:53:19 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *largestr, const char *smallstr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (smallstr[0] == 0)
		return ((char *)largestr);
	while (largestr[i] && i < len)
	{
		j = 0;
		while (smallstr[j] && largestr[i + j]
			&& (smallstr[j] == largestr[i + j]) && ((i + j) < len))
			j++;
		if (smallstr[j] == '\0')
			return ((char *)&largestr[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*big = "Foo Bar Baz";
	const char	*little = "Baz";

	printf("original :  %s\n", ft_strnstr(big, little, 11));
	return (0);
}
	*/
