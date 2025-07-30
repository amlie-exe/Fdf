/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:05:52 by amhan             #+#    #+#             */
/*   Updated: 2025/05/14 17:22:03 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*result;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
char	ft_test(unsigned int i, char c);

int	main(void)
{
	char	*original;
	char	*update;

	original = "la libft me fatigue, help";
	update = ft_strmapi(original, ft_test);
	printf("Before : %s\n", original);
	if (update)
	{
		printf("After : %s\n", update);
		free(update);
	}
}
char	ft_test(unsigned int i, char c)
{
	char	c_update;

	c_update = c;
	if (i % 2 == 0)
		c_update = ft_toupper(c);
	else
		c_update = ft_tolower(c);
	return (c_update);
}
	*/