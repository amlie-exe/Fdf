/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:08:43 by amhan             #+#    #+#             */
/*   Updated: 2025/05/10 14:50:39 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	sub_len;
	char	*new_str;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	sub_len = (s_len - start);
	if (sub_len > len)
		sub_len = len;
	new_str = malloc(sub_len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
int	main(void)
{
	char	*new_str;

	char	s[] = "Laurent veut un kebab";
	new_str = ft_substr(s, 0, 7);
	printf("%s\n", new_str);
	free(new_str);
	return (0);
}
*/
