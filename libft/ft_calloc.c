/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:19:44 by amhan             #+#    #+#             */
/*   Updated: 2025/05/06 15:01:12 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_items, size_t size_items)
{
	void	*ptr;

	ptr = malloc (n_items * size_items);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n_items * size_items);
	return (ptr);
}
/*
int	main(void)
{
	size_t n = 5;
	size_t	size = sizeof(int);
	int *arr = (int *)ft_calloc(n, size);

	if (!arr)
		return (1);
	size_t	i;
	while (i < n)
	{
		if (arr[i] != 0)
		{
			printf("Erreur : arr [%zu] = %d (doit être 0)\n", i, arr[i]);
			free(arr);
			return (1);
		}
		i++;
	}
	printf("Tout est initialisé à 0");
	free(arr);
	return (0);
}
	*/