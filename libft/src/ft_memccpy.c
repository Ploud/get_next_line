/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:50:25 by jsobel            #+#    #+#             */
/*   Updated: 2018/04/16 17:28:53 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s1 + i) = *((unsigned char *)s2 + i);
		if (*((unsigned char *)s2 + i) == (unsigned char)c)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
