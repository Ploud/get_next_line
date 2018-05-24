/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:28:14 by jsobel            #+#    #+#             */
/*   Updated: 2018/04/12 17:43:00 by jsobel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*tab;
	long	i;
	int		size;

	i = n;
	size = n == 0 ? 1 : 0;
	while (i != 0)
	{
		i /= 10;
		size++;
	}
	i = n;
	size = n < 0 ? size + 1 : size;
	if (!(tab = malloc(size + 1)))
		return (NULL);
	tab[size] = 0;
	tab[0] = n < 0 ? '-' : '0';
	i = n < 0 ? -i : i;
	while (i >= 1)
	{
		tab[size - 1] = (i % 10) + 48;
		i /= 10;
		size--;
	}
	return (tab);
}
