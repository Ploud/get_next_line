/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:00:52 by jsobel            #+#    #+#             */
/*   Updated: 2018/04/13 16:41:54 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tabd;
	char	*tabs;
	size_t	i;

	tabd = (char *)dest;
	tabs = (char *)src;
	i = n;
	if (tabs < tabd)
	{
		while (i)
		{
			i--;
			tabd[i] = tabs[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
