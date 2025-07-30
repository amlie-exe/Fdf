/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:51:19 by amhan             #+#    #+#             */
/*   Updated: 2025/05/11 16:43:10 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && to_trim(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while ((end > start) && to_trim(s1[end - 1], set))
		end--;
	s2 = malloc((end - start + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (start < end)
		s2[i++] = s1[start++];
	s2[i] = '\0';
	return (s2);
}

static int	to_trim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*str;
	char	*set_to_trim;
	char	*trimmed_str;

	str = "hbbmmeeehbIt's me, Mario !bbbhmeeeeeh";
	set_to_trim = "hbme";
	printf("Original: %s\n", str);
	printf("Set: %s\n", set_to_trim);
	trimmed_str = ft_strtrim(str, set_to_trim);
	if (trimmed_str)
	{
		printf("After trim: %s\n", trimmed_str);
		free(trimmed_str);
	}
	return (0);
}
	*/