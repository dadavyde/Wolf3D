/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:31:24 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/13 21:31:27 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;

	if (lst == NULL || f == NULL)
		return (NULL);
	begin = f(lst);
	new = begin;
	lst = lst->next;
	while (lst != NULL)
	{
		if (new == NULL)
			break ;
		new->next = f(lst);
		new = new->next;
		lst = lst->next;
	}
	new = NULL;
	return (begin);
}
