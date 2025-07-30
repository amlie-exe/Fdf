/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:08:40 by amhan             #+#    #+#             */
/*   Updated: 2025/05/14 18:32:18 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void	ft_test(unsigned int i, char *c);

int	main(void)
{
	char	str[] = "la libft me fatigue, help";

	printf("Before : %s\n", str);
	ft_striteri(str, ft_test);
	printf("After : %s\n", str);
}

void	ft_test(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}
	*/