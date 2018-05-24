/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:50:30 by jsobel            #+#    #+#             */
/*   Updated: 2018/04/12 18:59:10 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*tab;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!(tab = malloc(i + 1)))
		return (NULL);
	tab[i] = 0;
	i = 0;
	while (s[i])
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	return (tab);
}
