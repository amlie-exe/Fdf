/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:13:37 by amhan             #+#    #+#             */
/*   Updated: 2025/05/19 19:33:07 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char sep);
static char		*word_copy(char const *s, int start, int end);
static void		*ft_free(char **result, size_t count);

char	**ft_split(char const *s, char c)
{
	size_t	start;
	size_t	i;
	size_t	j;
	char	**result;

	result = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (NULL);
	i = 0;
	j = 0;
	while ((s[i] != '\0') && (j < word_count(s, c)))
	{
		while ((s[i] != '\0') && (s[i] == c))
			i++;
		start = i;
		while ((s[i] != '\0') && (s[i] != c))
			i++;
		result[j] = word_copy(s, start, i);
		if (!result[j])
			return (ft_free(result, j));
		j++;
	}
	result[j] = NULL;
	return (result);
}

static size_t	word_count(char const *s, char sep)
{
	int	count;
	int	sep_trigger;

	count = 0;
	sep_trigger = 0;
	while (*s)
	{
		if ((*s != sep) && (sep_trigger == 0))
		{
			sep_trigger = 1;
			count++;
		}
		else if (*s == sep)
			sep_trigger = 0;
		s++;
	}
	return (count);
}

static char	*word_copy(char const *s, int start, int end)
{
	char	*word;
	size_t	i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **result, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = "Je ne suis pas sure de ce que je fais";
	char	**arr_words;
	int		k;

	k = 0;
	printf("Chaîne originale: \"%s\"\n", s);
	printf("Nombre de mots : %zu\n", word_count(s, ' '));
	arr_words = ft_split(s, ' ');
	if (arr_words)
	{
		printf("Résultat de ft_split :\n");
		while (arr_words[k] != NULL)
		{
			printf("Mot %d: %s\n", k, arr_words[k]);
			free(arr_words[k]); // Libère la mémoire de chaque mot
			k++;
		}
		free(arr_words);
		// Libère la mémoire du tableau de pointeurs lui-même
	}
	return (0);
}
	*/
