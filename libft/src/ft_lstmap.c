/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:32:41 by jsobel            #+#    #+#             */
/*   Updated: 2018/04/18 14:52:39 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!(new = f(lst)))
		return (NULL);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp->next = f(lst)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
