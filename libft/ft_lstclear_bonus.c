/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:58:42 by amhan             #+#    #+#             */
/*   Updated: 2025/05/19 14:50:45 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !(*lst) || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
/*
static void	del_content(void *content);

int	main(void)
{
	t_list	*lst;
	t_list	*node2;
	t_list	*node3;
	char	*s1;
	char	*s2;
	char	*s3;

	// Création des contenus (chaînes dupliquées dynamiquement)
	s1 = strdup("Hello");
	s2 = strdup("World");
	s3 = strdup("42");
	// Création des nodes de la liste
	lst = ft_lstnew(s1);
	node2 = ft_lstnew(s2);
	node3 = ft_lstnew(s3);
	// Chaînage des nodes
	lst->next = node2;
	node2->next = node3;
	// Affichage avant la libération
	printf("Before :\n%s\n%s\n%s\n", s1, s2, s3);
	// Libération de la chaîne
	ft_lstclear(&lst, del_content);
	if (lst == NULL)
		printf("After : Liste correctement libérée\n");
	return (0);
}
static void	del_content(void *content)
{
	free(content);
}
	*/