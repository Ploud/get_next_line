/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:45:13 by jsobel            #+#    #+#             */
/*   Updated: 2018/04/16 15:21:31 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t destl;
	size_t srcl;

	i = ft_strlen(dest);
	destl = i;
	srcl = ft_strlen(src);
	j = 0;
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	if (size < destl)
		return (srcl + size);
	return (srcl + destl);
}
