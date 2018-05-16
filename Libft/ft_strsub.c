/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:04:30 by jsobel            #+#    #+#             */
/*   Updated: 2018/04/12 15:24:58 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(tab = malloc(len + 1)))
		return (NULL);
	tab[len] = 0;
	i = 0;
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	return (tab);
}
