/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:42:07 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/24 08:41:53 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*maped;
	t_list	*il1;
	t_list	*il2;

	if (!lst || !del)
		return (NULL);
	maped = ft_lstnew(f(lst->content));
	lst = lst->next;
	il1 = maped;
	while (lst)
	{
		il2 = ft_lstnew(f(lst->content));
		il1->next = il2;
		il1 = il2;
		lst = lst->next;
	}
	return (maped);
}
